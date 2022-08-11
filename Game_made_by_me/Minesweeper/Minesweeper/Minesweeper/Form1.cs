using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Minesweeper
{

    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        const int BOMB = 99, BLANK = 0, FLAG = 1;
        int[] mine_pos = new int[99];
        int[,] board_record = new int[20, 20];
        bool[,] visited = new bool[20, 20];
        int[,] bomb_cnt = new int[20, 20];
        Button[,] board = new Button[20, 20];
        

        private void Form1_Load(object sender, EventArgs e)
        {
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    board_record[i, j] = BLANK;
                }
            }

            Random rnd = new Random();
            for (int i = 0; i < 80; i++) // Initiate bombs
            {
                int row, col;
                do
                {
                    mine_pos[i] = rnd.Next(0, 400);
                    row = mine_pos[i] / 20;
                    col = mine_pos[i] % 20;
                } while (board_record[row, col] == BOMB);

                board_record[row, col] = BOMB; 
            }
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 20; j++)
                {

                    visited[i, j] = new bool();
                    bomb_cnt[i, j] = new int();
                }
            }
            for (int i = 0; i < 20; i ++)
            {
                for (int j = 0; j < 20; j++)
                {
                    board[i, j] = new Button();
                    Controls.Add(board[i, j]);
                    board[i, j].SetBounds(50 + j * 30, 20 + i * 30, 25, 25);
                    board[i, j].BackColor = Color.DarkGray;
                    board[i, j].MouseUp += new MouseEventHandler(this.BoardBtn_Click);
                    board[i, j].Text = "";
                }
            }

            time_lbl.Text = "Elapsed Time: 0 sec(s)";
            flag_lbl.Text = "Num of Flag: 80";
        }

        int clicked_time = 0;
        int flag_num = 80;
        private void BoardBtn_Click(object sender, MouseEventArgs e)
        {
            int i = ExtensionMethod.CoordinatesOf(board, (Object)sender).Item1;
            int j = ExtensionMethod.CoordinatesOf(board, (Object)sender).Item2;

            switch (e.Button)
            {
                case (MouseButtons.Left):
                    if (clicked_time == 0 && board_record[i, j] == BOMB) // first click is a bomb 
                    {
                        board_record[i, j] = BLANK;
                        if (i > 0 && j > 0)
                        {
                            if (board_record[i - 1, j - 1] == BOMB)
                                PutBomb();
                            else
                                board_record[i - 1, j - 1] = BOMB;
                        }
                        else
                            PutBomb();
                    }
                    if (board_record[i, j] == BOMB)
                    {
                        board[i, j].Text = "99";
                        Lose();
                    }
                    else
                    {
                        for (int k = 0; k < 20; k++)
                        {
                            for (int l = 0; l < 20; l++)
                            {
                                visited[k, l] = false;
                                bomb_cnt[k, l] = 0;
                            }
                        }

                        DFS(i, j, visited, 0);
                    }
                    clicked_time++;
                    break;

                case (MouseButtons.Right):
                    Console.WriteLine("hi");
                    if (board[i, j].Text == "")
                    {
                        board[i, j].Text = "F";
                        flag_num--;
                        flag_lbl.Text = $"Num of Flag: {flag_num}";
                    }

                    else if (board[i, j].Text == "F")
                    {
                        board[i, j].Text = "";
                        flag_num++;
                        flag_lbl.Text = $"Num of Flag: {flag_num}";
                    }

                    break;

                default:
                    break;
            }
            
        }
        private void DFS(int i, int j, bool[,] visited, int index)
        {
            if (i < 0 || i > 19 || j < 0 || j > 19 || visited[i, j] == true)
                return;

            if (board_record[i, j] == BOMB)
                return;
            else
            {
                switch (index)
                {
                    case -4:
                        if (bomb_cnt[i + 1, j + 1] != 0) 
                            return;
                        break;
                    case -3:
                        if (bomb_cnt[i + 1, j] != 0)
                            return;
                        break;
                    case -2:                                        
                        if (bomb_cnt[i + 1, j - 1] != 0)
                            return;
                        break;
                    case -1:
                        if (bomb_cnt[i, j + 1] != 0)
                            return;
                        break;
                    case 1:
                        if (bomb_cnt[i, j - 1] != 0)
                            return;
                        break;
                    case 2:
                        if (bomb_cnt[i - 1, j + 1] != 0)
                            return;
                        break;
                    case 3:
                        if (bomb_cnt[i - 1, j] != 0)
                            return;
                        break;
                    case 4:
                        if (bomb_cnt[i - 1, j - 1] != 0)
                            return;
                        break;
                    default: break;
                }
            }

            bool shouldDiscover = true;
            if (i > 0)
            {
                if (j > 0)
                    if (board_record[i - 1, j - 1] == BOMB)
                    {
                        shouldDiscover = false;
                        bomb_cnt[i, j]++;
                    }
                if (board_record[i - 1, j] == BOMB)
                {
                    shouldDiscover = false;
                    bomb_cnt[i, j]++;
                }
                if (j < 19)
                    if (board_record[i - 1, j + 1] == BOMB)
                    {
                        shouldDiscover = false;
                        bomb_cnt[i, j]++;
                    }
            }
            if (j > 0)
                if (board_record[i, j - 1] == BOMB)
                {
                    shouldDiscover = false;
                    bomb_cnt[i, j]++;
                }
            if (j < 19)
                if (board_record[i, j + 1] == BOMB)
                {
                    shouldDiscover = false;
                    bomb_cnt[i, j]++;
                }
            if (i < 19)
            {
                if (j > 0)
                    if (board_record[i + 1, j - 1] == BOMB)
                    {
                        shouldDiscover = false;
                        bomb_cnt[i, j]++;
                    }
                if (board_record[i + 1, j] == BOMB)
                {
                    shouldDiscover = false;
                    bomb_cnt[i, j]++;
                }
                if (j < 19)
                    if (board_record[i + 1, j + 1] == BOMB)
                    {
                        shouldDiscover = false;
                        bomb_cnt[i, j]++;
                    }
            }

            visited[i, j] = true;
            if (shouldDiscover)
            {
                if (i != 0 && j != 0)
                    DFS(i - 1, j - 1, visited, -4);
                if (i != 0)
                    DFS(i - 1, j, visited, -3);
                if (i != 0 && j != 19)
                    DFS(i - 1, j + 1, visited, -2);
                if (j != 0)
                    DFS(i, j - 1, visited, -1);
                if (j != 19)
                    DFS(i, j + 1, visited, 1);
                if (i != 19 && j != 19)
                    DFS(i + 1, j - 1, visited, 2);
                if (i != 19)
                    DFS(i + 1, j, visited, 3);
                if (i != 19 && j != 19)
                    DFS(i + 1, j + 1, visited, 4);
            }
            board[i, j].BackColor = Color.LightGray;
            board[i, j].Enabled = false;
            if (bomb_cnt[i, j] != 0)
                board[i, j].Text = bomb_cnt[i, j].ToString();
            return;
        }

        int elapsed_time = 0;
        private void timer1_Tick(object sender, EventArgs e)
        {
            elapsed_time++;
            time_lbl.Text = $"Elapsed Time: {elapsed_time} sec(s)";
        }

        private void Retry_Btn_Click(object sender, EventArgs e)
        {
            //clicked_time = 0;
            //flag_num = 80;
            //for (int i = 0; i < 20; i++)
            //{
            //    for (int j = 0; j < 20; j++)
            //    {
            //        board[i, j].Enabled = true;
            //    }
            //}
            //for (int k = 0; k < 20; k++)
            //{
            //    for (int l = 0; l < 20; l++)
            //    {
            //        visited[k, l] = false;
            //        bomb_cnt[k, l] = 0;
            //    }
            //}
            //timer1.Enabled = true;
            Form1_Load(sender, e);
            Application.Restart();
        }

        private void PutBomb()
        {
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    if (board_record[i, j] != BOMB)
                        board_record[i, j] = BOMB;
                    else
                        continue;
                }
            }
        }

        private void Lose()
        {
            MessageBoxButtons buttons = MessageBoxButtons.OK;
            MessageBoxIcon icon = MessageBoxIcon.Stop;
            string title = "LOSE";
            MessageBox.Show("YOU LOSE!", title, buttons, icon);
            timer1.Enabled = false;
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    if (board_record[i, j] == BOMB)
                    {
                        if (board[i, j].Text != "F")
                        {
                            board[i, j].ForeColor = Color.Red;
                            board[i, j].Text = "99";

                        }
                    }
                    else
                    {
                        if (board[i, j].Text == "F")
                        {
                            board[i, j].ForeColor = Color.Red;
                        }
                    }
                    board[i, j].Enabled = false;
                }
            }
        }

    }



    public static class ExtensionMethod
    {
        public static Tuple<int, int> CoordinatesOf<T>(this T[,] matrix, T value) // Get the coordinates of 2D array
        {
            int w = matrix.GetLength(0); // width
            int h = matrix.GetLength(1); // height

            for (int x = 0; x < w; ++x)
            {
                for (int y = 0; y < h; ++y)
                {
                    if (matrix[x, y].Equals(value))
                        return Tuple.Create(x, y);
                }
            }

            return Tuple.Create(-1, -1);
        }
    }

}
