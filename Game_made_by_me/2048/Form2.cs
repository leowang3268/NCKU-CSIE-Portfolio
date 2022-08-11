using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace MMXLVIII
{
    public partial class Form2 : Form
    {
        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
            this.Location = Owner.Location;
            this.Size = Owner.Size;
        }

        Button[] button = new Button[16];
        Label[] horizontalBodrer = new Label[5];
        Label[] verticalBorder = new Label[5];
        public Form2()
        {
            InitializeComponent();
            this.KeyPreview = true; // Add this line to let keydown event work
            for (int i = 0; i < 16; i++)
            {
                int col = i % 4, row = i / 4;
                button[i] = new Button(); //68 158
                button[i].SetBounds(38 + col * 70, 126 + row * 70, 60, 60); //x, y, width, height
                button[i].BackColor = Color.FromArgb(255, 255, 192);
                Controls.Add(button[i]);
            }
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            string docPath = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
            string savePath = Path.Combine(docPath, "HighRecord.txt");
            if(File.Exists(savePath))
            {
                StreamReader sr = new StreamReader(savePath);
                int highestScore = Convert.ToInt32(sr.ReadLine());
                HighScores.Text = highestScore.ToString();
                sr.Close();
            }

            for (int i = 0; i < 16; i++)
                button[i].Enabled = true;
            backBtn.Enabled = false;
            retryBtn.Enabled = false;
            Scores.Text = "0000";
            for (int i = 0; i < 16; i++) 
                button[i].Visible = false;
            Random init_rnd = new Random();
            int pos1 = init_rnd.Next(0, 16);
            int pos2;
            do
            {
                pos2 = init_rnd.Next(0, 16);
            } while (pos2 == pos1);
            button[pos1].Visible = true;
            button[pos2].Visible = true;
            Random value_rnd = new Random();
            int value1, value2;
            value1 = (value_rnd.Next(0, 10) == 0) ? 4 : 2; // 4Τ1/10诀瞯ネΘ
            value2 = (value_rnd.Next(0, 10) == 0) ? 4 : 2;
            button[pos1].Text = value1.ToString();
            button[pos2].Text = value2.ToString();
        }

        bool move = false;
        private void generateNew()
        {
            int new_pos;
            Random new_rnd = new Random();
            do
            {
                new_pos = new_rnd.Next(0, 16);
            } while (button[new_pos].Visible == true);
            button[new_pos].Visible = true;
            //MessageBox.Show(new_pos.ToString());
            Random value_rnd = new Random();
            int value;
            value = (value_rnd.Next(0, 10) == 0) ? 4 : 2;
            button[new_pos].Text = value.ToString();
            move = false;
        }

        /*
        bool[] toVisible = new bool[16];
        bool[] toInvisible = new bool[16];
        bool[] textChanged = new bool[16];
        string[] previousText = new string[16];
        */

        bool[] currentVisible = new bool[16];
        string[] currentText = new string[16];
        private void Form2_KeyDown(object sender, KeyEventArgs e)
        {
            bool[] merge = new bool[16];
            
            switch (e.KeyCode)
            {
                case Keys.W:
                    backBtn.Enabled = true;
                    retryBtn.Enabled = true;
                    /*
                    for (int i = 0; i < 16; i++)
                    {
                        merge[i] = false;
                        toVisible[i] = false;
                        toInvisible[i] = false;
                        textChanged[i] = false;
                        //
                    }
                    */
                    
                    // record the map before moving
                    for (int i = 0; i < 16; i++)
                    {
                        currentVisible[i] = false; // Reset first
                        if (button[i].Visible == true)
                            currentVisible[i] = true;
                        currentText[i] = button[i].Text;
                    }

                    for (int i = 0; i < 16; i++)
                    {
                        int col = i % 4, row = i / 4;
                        if (button[i].Visible == true)
                        {
                            int move_then_merge = 0;
                            for (int j = 1; j <= row; j++)
                            {
                                if (button[i - 4 * j].Visible == false)
                                {
                                    button[i - 4 * (j - 1)].Visible = false;
                                    //toInvisible[i - 4 * (j - 1)] = true;
                                    button[i - 4 * j].Visible = true;
                                    //toVisible[i - 4 * j] = true;
                                    //previousText[i - 4 * j] = button[i - 4 * j].Text;
                                    button[i - 4 * j].Text = button[i].Text;
                                    //textChanged[i - 4 * j] = true;
                                    move = true;
                                    move_then_merge++;
                                }
                                else  // button[i - 4 * j].Visible == true
                                {
                                    if (button[i - 4 * move_then_merge].Text == button[i - 4 * j].Text && merge[i - 4 * j] == false)  // ぃΩㄖ场
                                    {
                                        button[i - 4 * move_then_merge].Visible = false;
                                        //toInvisible[i - 4 * move_then_merge] = true;
                                        int new_value = Convert.ToInt32(button[i - 4 * move_then_merge].Text) * 2;
                                        //previousText[i - 4 * j] = button[i - 4 * j].Text;
                                        Scores.Text = (Convert.ToInt32(Scores.Text) + new_value).ToString("D4");
                                        button[i - 4 * j].Text = new_value.ToString();
                                        //textChanged[i - 4 * j] = true;
                                        merge[i - 4 * j] = true;
                                        move = true;
                                    }
                                    break;
                                }
                            }
                        }
                    }

                    if (move == true)
                        generateNew();
                    break;

                case Keys.S:
                    backBtn.Enabled = true;
                    retryBtn.Enabled = true;
                    /*
                    for (int i = 0; i < 16; i++)
                    {
                        merge[i] = false;
                        toVisible[i] = false;
                        toInvisible[i] = false;
                        textChanged[i] = false;
                        //
                    }
                    */

                    // record the map before moving
                    for (int i = 0; i < 16; i++)
                    {
                        currentVisible[i] = false; // Reset first
                        if (button[i].Visible == true)
                            currentVisible[i] = true;
                        currentText[i] = button[i].Text;
                    }

                    for (int i = 15; i >= 0; i--)
                    {
                        int col = i % 4, row = i / 4;
                        if (button[i].Visible == true)
                        {
                            int move_then_merge = 0;
                            for (int j = 1; j <= 3 - row; j++)
                            {
                                if (button[i + 4 * j].Visible == false)
                                {
                                    button[i + 4 * (j - 1)].Visible = false;
                                    //toInvisible[i + 4 * (j - 1)] = true;
                                    button[i + 4 * j].Visible = true;
                                    //toVisible[i + 4 * j] = true;
                                    //previousText[i + 4 * j] = button[i + 4 * j].Text;
                                    button[i + 4 * j].Text = button[i].Text;
                                    //textChanged[i + 4 * j] = true;
                                    move = true;
                                    move_then_merge++;
                                }
                                else  // button[i - 4 * j].Visible == true
                                {
                                    if (button[i + 4 * move_then_merge].Text == button[i + 4 * j].Text && merge[i + 4 * j] == false)
                                    {
                                        button[i + 4 * move_then_merge].Visible = false;
                                        //toInvisible[i + 4 * move_then_merge] = true;
                                        int new_value = Convert.ToInt32(button[i + 4 * move_then_merge].Text) * 2;
                                        Scores.Text = (Convert.ToInt32(Scores.Text) + new_value).ToString("D4");
                                        //previousText[i + 4 * j] = button[i + 4 * j].Text;
                                        button[i + 4 * j].Text = new_value.ToString();
                                        //textChanged[i + 4 * j] = true;
                                        merge[i + 4 * j] = true;
                                        move = true;
                                    }
                                    break;
                                }
                            }
                        }
                    }

                    if (move == true)
                        generateNew();
                    break;

                case Keys.A:
                    backBtn.Enabled = true;
                    retryBtn.Enabled = true;
                    /*
                    for (int i = 0; i < 16; i++)
                    {
                        merge[i] = false;
                        toVisible[i] = false;
                        toInvisible[i] = false;
                        textChanged[i] = false;
                        //
                    }
                    */

                    // record the map before moving
                    for (int i = 0; i < 16; i++)
                    {
                        currentVisible[i] = false; // Reset first
                        if (button[i].Visible == true)
                            currentVisible[i] = true;
                        currentText[i] = button[i].Text;
                    }

                    for (int i = 0; i < 16; i++)
                    {
                        int col = i % 4, row = i / 4;
                        if (button[i].Visible == true)
                        {
                            int move_then_merge = 0;
                            for (int j = 1; j <= col; j++)
                            {
                                if (button[i - j].Visible == false)
                                {
                                    button[i - (j - 1)].Visible = false;
                                    //toInvisible[i - (j - 1)] = true;
                                    button[i - j].Visible = true;
                                    //toVisible[i - j] = true;
                                    //previousText[i - j] = button[i - j].Text;
                                    button[i - j].Text = button[i].Text;
                                    //textChanged[i - j] = true;
                                    move = true;
                                    move_then_merge++;
                                }
                                else  // button[i - 4 * j].Visible == true
                                {
                                    if (button[i - move_then_merge].Text == button[i - j].Text && merge[i - j] == false)  // ぃΩㄖ场
                                    {
                                        button[i - move_then_merge].Visible = false;
                                        //toInvisible[i - move_then_merge] = true;
                                        int new_value = Convert.ToInt32(button[i - move_then_merge].Text) * 2;
                                        Scores.Text = (Convert.ToInt32(Scores.Text) + new_value).ToString("D4");
                                        //previousText[i - j] = button[i - j].Text;
                                        button[i - j].Text = new_value.ToString();
                                        //textChanged[i - j] = true;
                                        merge[i - j] = true;
                                        move = true;
                                    }
                                    break;
                                }
                            }
                        }
                    }

                    if (move == true)
                        generateNew();
                    break;

                case Keys.D:
                    backBtn.Enabled = true;
                    retryBtn.Enabled = true;
                    /*
                    for (int i = 0; i < 16; i++)
                    {
                        merge[i] = false;
                        toVisible[i] = false;
                        toInvisible[i] = false;
                        textChanged[i] = false;
                        //
                    }
                    */

                    // record the map before moving
                    for (int i = 0; i < 16; i++)
                    {
                        currentVisible[i] = false; // Reset first
                        if (button[i].Visible == true)
                            currentVisible[i] = true;
                        currentText[i] = button[i].Text;
                    }

                    for (int i = 15; i >= 0; i--)
                    {
                        int col = i % 4, row = i / 4;
                        if (button[i].Visible == true)
                        {
                            int move_then_merge = 0;
                            for (int j = 1; j <= 3 - col; j++)
                            {
                                if (button[i + j].Visible == false)
                                {
                                    button[i + (j - 1)].Visible = false;
                                    //toInvisible[i + (j - 1)] = true;
                                    button[i + j].Visible = true;
                                    //toVisible[i + j] = true;
                                    //previousText[i + j] = button[i + j].Text;
                                    button[i + j].Text = button[i].Text;
                                    //textChanged[i + j] = true;
                                    move = true;
                                    move_then_merge++;
                                }
                                else  // button[i + j].Visible == true
                                {
                                    if (button[i + move_then_merge].Text == button[i + j].Text && merge[i + j] == false)
                                    {
                                        button[i + move_then_merge].Visible = false;
                                        //toInvisible[i + move_then_merge] = true;
                                        int new_value = Convert.ToInt32(button[i + move_then_merge].Text) * 2;
                                        Scores.Text = (Convert.ToInt32(Scores.Text) + new_value).ToString("D4");
                                        //previousText[i + j] = button[i + j].Text;
                                        button[i + j].Text = new_value.ToString();
                                        //textChanged[i + j] = true;
                                        merge[i + j] = true;
                                        move = true;
                                    }
                                    break;
                                }
                            }
                        }
                    }

                    if (move == true)
                        generateNew();
                    break;

                case Keys.B:
                    backBtn_Click(sender, e);
                    break;

                case Keys.R:
                    RetryBtn_Click(sender, e);
                    break;

                case Keys.Q:
                    Application.Exit();
                    break;

            }

            int button_show_cnt = 0;
            for (int i = 0; i < 16; i++)
            {
                if (button[i].Visible == true)
                    button_show_cnt++;
            }
            if (button_show_cnt == 16)
            {
                if (isLose())
                {
                    MessageBox.Show("You Lose");
                    for (int i = 0; i < 16; i++)
                        button[i].Enabled = false;
                    backBtn.Enabled = false;
                    int score = Convert.ToInt32(Scores.Text);
                    int highest_score = Convert.ToInt32(HighScores.Text);
                    if (score > highest_score)
                        HighScores.Text = Scores.Text;

                    string docPath = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
                    string savePath = Path.Combine(docPath, "HighRecord.txt");
                    using (StreamWriter outputFile = new StreamWriter(savePath))
                    {
                        outputFile.WriteLine(HighScores.Text);
                    }
                }
            }

        }     
        private bool isLose()
        {
            bool canMove = false;
            bool[] up_merge = new bool[16];
            bool[] down_merge = new bool[16];
            bool[] left_merge = new bool[16];
            bool[] right_merge = new bool[16];
            for (int i = 0; i < 16; i++)
                up_merge[i] = false;

            for (int i = 0; i < 16; i++)
                down_merge[i] = false;

            for (int i = 0; i < 16; i++)
                left_merge[i] = false;

            for (int i = 0; i < 16; i++)
                right_merge[i] = false;

            // Can move up?
            for (int i = 0; i < 16; i++)
            {               
                int col = i % 4, row = i / 4;
                if (i >= 4)
                {
                    if (button[i].Text == button[i - 4].Text && up_merge[i - 4] == false)  // ぃΩㄖ场
                    {
                        up_merge[i - 4] = true;
                        canMove = true;
                    }
                }
            }

            // Can move down?
            for (int i = 15; i >= 0; i--)
            {
                int col = i % 4, row = i / 4;
                if (i < 12)
                {
                    if (button[i].Text == button[i + 4].Text && down_merge[i + 4] == false)   // ぃΩㄖ场
                    {
                        down_merge[i + 4] = true;
                        canMove = true;
                    }
                }
            }

            // Can move left?
            for (int i = 0; i < 16; i++)
            {
                int col = i % 4, row = i / 4;
                if (col > 0)
                {
                    if (button[i].Text == button[i - 1].Text && left_merge[i - 1] == false)   // ぃΩㄖ场
                    {
                        left_merge[i - 1] = true;
                        canMove = true;
                    }
                }                           
            }

            // Can move right?
            for (int i = 15; i >= 0; i--)
            {
                int col = i % 4, row = i / 4;
                if (col < 3)
                {
                    if (button[i].Text == button[i + 1].Text && right_merge[i + 1] == false)   // ぃΩㄖ场
                    {
                        right_merge[i + 1] = true;
                        canMove = true;
                    }
                }                
            }

            return (!canMove);
        }

        private void backBtn_Click(object sender, EventArgs e)
        {
            /*
            for (int i = 0; i < 16; i++)
            {
                if (toVisible[i])
                    button[i].Visible = false;
                if (toInvisible[i])
                    button[i].Visible = true;
                if (textChanged[i])
                    button[i].Text = previousText[i];
            }
            */
            backBtn.Enabled = false;
            for (int i = 0; i < 16; i++)
            {
                button[i].Visible = false;
                if (currentVisible[i] == true)
                    button[i].Visible = true;
                button[i].Text = currentText[i];
            }
        }

        private void RetryBtn_Click(object sender, EventArgs e)
        {
            Form2_Load(sender, e);
        }

        private void Form2_FormClosing(object sender, FormClosingEventArgs e)
        {
            Application.Exit();
        }
    }
}
