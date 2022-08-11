using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Pac_Man
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Button[] block = new Button[60];
        List<int> obstacle_index = new List<int>{11, 12, 14, 15, 17, 18, 21, 22, 27, 28, 34, 35, 41, 42, 47, 48, 54, 55};
        Label[] food = new Label[60];
        int food_cnt = 39; // 39 foods
        PictureBox pacman = new PictureBox();
        PictureBox blinky = new PictureBox();
        PictureBox inky = new PictureBox();
        Label score_label = new Label();
        Label life_label = new Label();
        private void Form1_Load(object sender, EventArgs e)
        {

            for (int i = 0; i < block.Length; i++)
            {
                block[i] = new Button();
                block[i].SetBounds((i % 10) * 60, (i / 10) * 60, 60, 60);
                block[i].Enabled = false;
                // blocks[i].Visible = false;

                Controls.Add(block[i]);
                if (obstacle_index.Contains(i))
                    block[i].BackColor = Color.Black;
                else
                {
                    food[i] = new Label();

                    if (i != 24 && i != 25 && i != 59)
                    {
                        food[i].SetBounds((i % 10) * 60 + 25, (i / 10) * 60 + 25, 10, 10); 
                        food[i].BackColor = Color.Orange;
                        // food[food_index].BringToFront();
                        Controls.Add(food[i]);
                        food[i].BringToFront();
                        // Console.WriteLine("it's here\n");
                    }
                    else
                    {
                        food[i].Visible = false;
                    }
                    block[i].BackColor = Color.FromArgb(18, 39, 203);
                }

            }
            //for (int i = 0; i < food.Length; i++)
            //{
            //    food[i].BringToFront();
            //}
            pacman.SetBounds(555, 315, 30, 30);
            //pacman.BackColor = Color.Yellow;
            pacman.Image = Image.FromFile("./pacman_right.png");
            pacman.SizeMode = PictureBoxSizeMode.StretchImage; // set mode to show the image
            Controls.Add(pacman);
            pacman.BringToFront(); // must be put after Controls.Add

            blinky.SetBounds(255, 135, 30, 30);
            //pacman.BackColor = Color.Yellow;
            blinky.Image = Image.FromFile("./blinky.png");
            blinky.SizeMode = PictureBoxSizeMode.StretchImage; // set mode to show the image
            Controls.Add(blinky);
            blinky.BringToFront(); // must be put after Controls.Add

            inky.SetBounds(315, 135, 30, 30);
            //pacman.BackColor = Color.Yellow;
            inky.Image = Image.FromFile("./inky.png");
            inky.SizeMode = PictureBoxSizeMode.StretchImage; // set mode to show the image
            Controls.Add(inky);
            inky.BringToFront(); // must be put after Controls.Add

            Controls.Add(score_label);
            score_label.Text = "Score: " + score.ToString("d4");
            score_label.TextAlign = ContentAlignment.MiddleCenter;
            score_label.ForeColor = Color.White;
            score_label.BackColor = Color.Black;
            score_label.SetBounds(245, 75, 100, 30);
            score_label.BringToFront();

            Controls.Add(life_label);
            life_label.Text = "Life: " + life.ToString("d2");
            life_label.TextAlign = ContentAlignment.MiddleCenter;
            life_label.ForeColor = Color.White;
            life_label.BackColor = Color.Black;
            life_label.SetBounds(245, 195, 100, 30);
            life_label.BringToFront();
        }

        bool up = false, down = false, left = false, right = false;

        int pacman_index = 59;
        int blinky_index = 24;
        int inky_index = 25;
        int tic_toc = 0;
        bool isWin = false, isLose = false;
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (isWin || isLose)
                return;
            pacman_index = (pacman.Top - 15) / 60 * 10 + (pacman.Left - 15) / 60;
            if (up)
            {
                if ((obstacle_index.Contains(pacman_index - 10)) || pacman.Top <= 15)
                    up = false;
                else
                {
                    pacman.Top -= 60;
                    pacman_index -= 10;
                }
            }
            else if (down)
            {
                if (obstacle_index.Contains(pacman_index + 10) || pacman.Top >= 315)
                    down = false;
                else
                {
                    pacman.Top += 60;
                    pacman_index += 10;
                }
            }
            else if (left)
            {
                if (obstacle_index.Contains(pacman_index - 1) || pacman.Left <= 15)
                    left = false;
                else
                {
                    pacman.Left -= 60;
                    pacman_index -= 1;
                }
            }
            else if (right)
            {
                if (obstacle_index.Contains(pacman_index + 1) || pacman.Left >= 555)
                    right = false;
                else
                {
                    pacman.Left += 60;
                    pacman_index += 1;
                }  
            }
            if (up || down || left || right)
            {
                eat_Food();
            }

            inky_index = (inky.Top - 15) / 60 * 10 + (inky.Left - 15) / 60;
            if (inky_index == pacman_index)
            {
                Lose();
            }
            if (tic_toc % 2 == 0 && tic_toc >= 10)
            {
                int inky_dest_x = pacman.Left + (pacman.Left - blinky.Left);
                if (inky_dest_x < 15)
                    inky_dest_x = 15;
                else if (inky_dest_x > 555)
                    inky_dest_x = 555;
                int inky_dest_y = pacman.Top + (pacman.Top - blinky.Top);
                if (inky_dest_y < 15)
                    inky_dest_y = 15;
                else if (inky_dest_y > 315)
                    inky_dest_y = 315;
                int inky_dest_index = (inky_dest_y - 15) / 60 * 10 + (inky_dest_x - 15) / 60;
                //if (obstacle_index.Contains(inky_dest_index))
                //{
                //    inky_dest_index -= 10; // destination move up
                //    if (obstacle_index.Contains(inky_dest_index))
                //    {
                //        if (inky_dest_index % 10 == 2 || inky_dest_index % 10 == 8)
                //            inky_dest_index += 11;
                //        else if (inky_index % 10 == 1 || inky_dest_index % 10 == 7)
                //            inky_dest_index += 9;
                //    }
                //}
                BFS(inky_dest_index, 1);
                int dest_index = path.Pop();
                inky.Left = (dest_index % 10) * 60 + 15;
                inky.Top = (dest_index / 10) * 60 + 15;
                inky_index = dest_index; //(inky.Top - 15) / 60 * 10 + (inky.Left - 15) / 60;
                Console.WriteLine("now inky is at " + inky_index);
                if (inky_index == pacman_index)
                {
                    Lose();
                }
            }

            blinky_index = (blinky.Top - 15) / 60 * 10 + (blinky.Left - 15) / 60;
            if (blinky_index == pacman_index)
            {
                Lose();
            }
            if (tic_toc % 2 == 1 || food_cnt <= 20)
            { 
                BFS(pacman_index, 2);
                int dest_index = path.Pop();
                blinky.Left = (dest_index % 10) * 60 + 15;
                blinky.Top = (dest_index / 10) * 60 + 15;
                blinky_index = dest_index; //(blinky.Top - 15) / 60 * 10 + (blinky.Left - 15) / 60;
                if (blinky_index == pacman_index)
                {
                    Lose();
                }
            }

            tic_toc++;
        }

        Stack<int> path = new Stack<int>();


        private class Block
        {
            // int index;
            public int visited; // 0 = unvisited, 1 = visiting, 2 = visited
            public int predecessor_index;
            public Block ()
            {
                //index = i;
                visited = 0;
                predecessor_index = -1;
            }
        }
        Block[] blocks = new Block[60];
        private void BFS(int dest, int ghost)
        {
            Queue<int> BFSqueue = new Queue<int>();
            for (int i = 0; i < 60; i ++)
            {
                blocks[i] = new Block();
            }
            if (ghost == 1)
                BFSqueue.Enqueue(inky_index);
            else if (ghost == 2)
                BFSqueue.Enqueue(blinky_index);
            if (ghost == 1) 
                Console.WriteLine("inky is " + inky_index);
            int iterate_time = 0;
            while (BFSqueue.Count > 0)
            {
                int current_index = BFSqueue.Dequeue();
                if (ghost == 1)
                    Console.WriteLine("current is " + current_index);
                if (!((current_index / 10 <= 0) || obstacle_index.Contains(current_index - 10)) && (blocks[current_index - 10].visited == 0)) // can go up
                { 
                    if (ghost == 1 && (current_index - 10) != blinky_index)
                    {
                        BFSqueue.Enqueue(current_index - 10);
                        if (ghost == 1)
                            Console.WriteLine($"now enqueue: {current_index - 10}");
                        blocks[current_index - 10].visited = 1;
                        blocks[current_index - 10].predecessor_index = current_index;
                    }
                    else if (ghost == 2 && (current_index - 10) != inky_index)
                    {
                        BFSqueue.Enqueue(current_index - 10);
                        if (ghost == 1)
                            Console.WriteLine($"now enqueue: {current_index - 10}");
                        blocks[current_index - 10].visited = 1;
                        blocks[current_index - 10].predecessor_index = current_index;
                    }
                }
                if (!((current_index / 10 >= 5) || obstacle_index.Contains(current_index + 10)) && (blocks[current_index + 10].visited == 0))
                {
                    if (ghost == 1 && (current_index + 10) != blinky_index)
                    {
                        BFSqueue.Enqueue(current_index + 10);
                        if (ghost == 1)
                            Console.WriteLine($"now enqueue: {current_index + 10}");
                        blocks[current_index + 10].visited = 1;
                        blocks[current_index + 10].predecessor_index = current_index;
                    }
                    else if (ghost == 2 && (current_index + 10) != inky_index)
                    {
                        BFSqueue.Enqueue(current_index + 10);
                        if (ghost == 1)
                            Console.WriteLine($"now enqueue: {current_index + 10}");
                        blocks[current_index + 10].visited = 1;
                        blocks[current_index + 10].predecessor_index = current_index;
                    }
                }
                if (!((current_index % 10 == 0) || obstacle_index.Contains(current_index - 1)) && (blocks[current_index - 1].visited == 0))
                {
                    if (ghost == 1 && (current_index - 1) != blinky_index)
                    {
                        BFSqueue.Enqueue(current_index - 1);
                        if (ghost == 1)
                            Console.WriteLine($"now enqueue: {current_index - 1}");
                        blocks[current_index - 1].visited = 1;
                        blocks[current_index - 1].predecessor_index = current_index;
                    }
                    else if (ghost == 2 && (current_index - 1) != inky_index)
                    {
                        BFSqueue.Enqueue(current_index - 1);
                        if (ghost == 1)
                            Console.WriteLine($"now enqueue: {current_index - 1}");
                        blocks[current_index - 1].visited = 1;
                        blocks[current_index - 1].predecessor_index = current_index;
                    }
                }
                if (!((current_index % 10 == 9) || obstacle_index.Contains(current_index + 1)) && (blocks[current_index + 1].visited == 0))
                {
                    if (ghost == 1 && (current_index + 1) != blinky_index)
                    {
                        BFSqueue.Enqueue(current_index + 1);
                        if (ghost == 1)
                            Console.WriteLine($"now enqueue: {current_index + 1}");
                        blocks[current_index + 1].visited = 1;
                        blocks[current_index + 1].predecessor_index = current_index;
                    }
                    else if (ghost == 2 && (current_index + 1) != inky_index)
                    {
                        BFSqueue.Enqueue(current_index + 1);
                        if (ghost == 1)
                            Console.WriteLine($"now enqueue: {current_index + 1}");
                        blocks[current_index + 1].visited = 1;
                        blocks[current_index + 1].predecessor_index = current_index;
                    }
                }

                blocks[current_index].visited = 2;
                if (ghost == 1)
                    Console.WriteLine("iterate time is " + iterate_time);
                iterate_time++;
            }
            int tmp = dest;

            //while (path.Count > 0)
            //    path.Pop();
            while (blocks[tmp].predecessor_index != -1)
            {
                if (ghost == 1)
                    Console.WriteLine($"{tmp} is going to be push into stack");
                path.Push(tmp);
                tmp = blocks[tmp].predecessor_index;
            }
        }

        int score = 0;
        private void eat_Food()
        {
            if (food[pacman_index].Visible == true) // havn't be eaten
            {
                score += 100;
                score_label.Text = "Score: " + score.ToString("d4");
                food[pacman_index].Visible = false;
                food_cnt--;
                if (food_cnt == 0)
                {
                    Win();
                }
            }
        }

        private void Win()
        {
            isWin = true;
            MessageBoxButtons buttons = MessageBoxButtons.RetryCancel;
            string title = "WON";
            DialogResult result = MessageBox.Show("YOU WON!", title, buttons, MessageBoxIcon.Information);
            if (result == DialogResult.Retry)
                Application.Restart();
            else
                Application.Exit();
            timer1.Enabled = false;
        }

        int life = 3;
        private void Lose()
        {
            isLose = true;
            if (life > 0)
            {
                string title = "DIED";
                MessageBoxButtons buttons = MessageBoxButtons.RetryCancel;
                DialogResult result = MessageBox.Show($"YOU DIED! {--life} lives remain", title, buttons, MessageBoxIcon.Stop);
                if (result == DialogResult.Retry) //再寫一個restart(復活在右下角，鬼回到原位，food不變)
                    Restart(); // self-defined function
                else
                    Application.Exit();
            }
            else
            {
                string title = "LOSE";
                MessageBoxButtons buttons = MessageBoxButtons.RetryCancel;
                DialogResult result = MessageBox.Show("YOU LOSE!", title, buttons, MessageBoxIcon.Stop);
                if (result == DialogResult.Retry)
                    Application.Restart();
                else
                    Application.Exit();
            }
            timer1.Enabled = false;
        }

        private void Restart()
        {
            pacman.Left = 555;
            pacman.Top = 315;
            pacman_index = 59;
            blinky.Left = 255;
            blinky.Top = 135;
            blinky_index = 24;
            inky.Left = 315;
            inky.Top = 135;
            inky_index = 25;
            up = false;
            down = false;
            left = false;
            right = false;
            tic_toc = 0;
            isWin = false;
            isLose = false;
            life_label.Text = "Life: " + life.ToString("d2");
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {       
            switch (e.KeyCode)
            {
                case (Keys.Up):
                    timer1.Enabled = true;
                    if (!(obstacle_index.Contains(pacman_index - 10)))
                    {
                        up = true;
                        down = false;
                        left = false;
                        right = false;
                    }
                    break;

                case (Keys.Down):
                    timer1.Enabled = true;
                    if (!(obstacle_index.Contains(pacman_index + 10)))
                    {
                        up = false;
                        down = true;
                        left = false;
                        right = false;
                    }
                    break;

                case (Keys.Left):
                    timer1.Enabled = true;
                    if (!(obstacle_index.Contains(pacman_index - 1)))
                    {
                        up = false;
                        down = false;
                        left = true;
                        right = false;
                    }
                    break;

                case (Keys.Right):
                    timer1.Enabled = true;
                    if (!(obstacle_index.Contains(pacman_index + 1)))
                    {
                        up = false;
                        down = false;
                        left = false;
                        right = true;
                    }
                    break;

            }
        }

    }
}
