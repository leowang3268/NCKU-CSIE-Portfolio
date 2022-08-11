using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing; // for Color.FromArgb
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms; 
//using System.Windows.Media;     // for Color.FromRgb

namespace Snake
{
    public partial class Form1 : Form
    {
        public class Snake : Label
        {
            public bool eat(ref Snake[] snake, ref Food food)
            {
                if(snake[0].Top <= food.Top && snake[0].Bottom >= food.Bottom && snake[0].Left <= food.Left && snake[0].Right >= food.Right)
                {
                    //MessageBox.Show("eat");
                    //food.Dispose();
                    return true;
                }
                return false;
            }
        }

        public class Food : Label
        {
            
        }

        public Form1()
        {
            InitializeComponent();
            
        }

        Snake[] snake = new Snake[4];
        Food food = new Food();
        int food_cnt = 0;
        private void Form1_Load(object sender, EventArgs e)
        {
            // set snake
            Array.Resize(ref snake, 4);
            for (int i = 0; i < snake.Length; i++)
            {
                snake[i] = new Snake();
                snake[i].SetBounds(200 - 20 * i, 140, 20, 20);
                Controls.Add(snake[i]);
                if (i == 0)
                    snake[i].BackColor = Color.FromArgb(255, 0, 0);
                else
                    snake[i].BackColor = Color.FromArgb(39, 168, 0); //39 168 0
            }

            //generate food
            food = new Food();
            food_cnt = 0;
            scoreLbl.Text = $"Score: {food_cnt}";
            food.SetBounds(300, 140, 20, 20);
            Controls.Add(food);
            food.BackColor = Color.FromArgb(255, 209, 5);
        }

        bool up = false, down = false, left = false, right = false;
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {       
            switch(e.KeyCode)
            {
                case (Keys.W):
                    if (snake[1].Top >= snake[0].Top) 
                    {
                        timer1.Enabled = true;
                        up = true;
                        down = false;
                        left = false;
                        right = false;
                    }                 
                    
                    break;

                case (Keys.S):
                    if (snake[1].Top <= snake[0].Top)
                    {
                        timer1.Enabled = true;
                        up = false;
                        down = true;
                        left = false;
                        right = false;
                    }                  

                    break;

                case (Keys.A):
                    if (snake[1].Left >= snake[0].Left)
                    {
                        timer1.Enabled = true;
                        up = false;
                        down = false;
                        left = true;
                        right = false;
                    }
                    break;

                case (Keys.D):
                    if (snake[1].Left <= snake[0].Left)
                    {
                        timer1.Enabled = true;
                        up = false;
                        down = false;
                        left = false;
                        right = true;
                    }
                    break;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            // When moving, record previous location
            int[] preX = new int[snake.Length];
            int[] preY = new int[snake.Length];
            preX[0] = snake[0].Left;
            preY[0] = snake[0].Top;

            if (up)
                    snake[0].Top -= 20;

            else if (down)
                    snake[0].Top += 20;

            else if (left)
                    snake[0].Left -= 20;

            else if (right)
                    snake[0].Left += 20;

            for (int i = 1; i < snake.Length; i++)
            {
                preX[i] = snake[i].Left;
                preY[i] = snake[i].Top;
                snake[i].Top = preY[i - 1];
                snake[i].Left = preX[i - 1];
            }
            
            // Bump into itself
            for (int i = 3; i < snake.Length; i++)
            {
                if(snake[0].Location == snake[i].Location)
                {
                    timer1.Enabled = false;
                    MessageBox.Show($"Lose! You Bump into yourself.\r\nScore: {food_cnt}");
                    for (int j = 0; j < snake.Length; j++)
                    {
                        snake[j].Visible = false;
                        snake[j].Dispose();
                    }
                    food.Visible = false;
                    food.Dispose();
                    Form1_Load(sender, e);
                }
            }
            
            // Bump into the wall
            if (snake[0].Top <= -10 || snake[0].Bottom >= 380 || snake[0].Left <= -10 || snake[0].Right >= 610)
            {
                timer1.Enabled = false;
                MessageBox.Show($"Lose! You Bump into the wall.\r\nScore: {food_cnt}");
                for (int j = 0; j < snake.Length; j++) 
                {
                    snake[j].Visible = false;
                    snake[j].Dispose();
                }
                food.Visible = false;
                food.Dispose();
                Form1_Load(sender, e);
            }

            // eat food and grow
            bool eaten = snake[0].eat(ref snake, ref food);          
            if (eaten)
            {
                Array.Resize(ref snake, snake.Length + 1);
                snake[snake.Length - 1] = new Snake();
                snake[snake.Length - 1].SetBounds(preX[snake.Length-2], preY[snake.Length-2], 20, 20);
                this.Controls.Add(snake[snake.Length - 1]);
                snake[snake.Length - 1].BackColor = Color.FromArgb(39, 168, 0); //39 168 0
                Random rnd = new Random();
                bool repeated;
                int posX, posY;
                do
                {
                    repeated = false;
                    posX = 20 + 20 * rnd.Next(0, 27);
                    posY = 20 + 20 * rnd.Next(0, 17);
                    for (int i = 0; i < snake.Length; i++)
                        if (posX == snake[i].Left && posY == snake[i].Top)
                            repeated = true;
                } while (repeated == true);
 
                food.SetBounds(posX, posY, 20, 20);
                food_cnt++;
                scoreLbl.Text = $"Score: {food_cnt}";
            }
        }
    }
}
