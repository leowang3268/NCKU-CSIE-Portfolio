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

namespace Mario
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        PictureBox[] brick = new PictureBox[100];

        PictureBox mario = new PictureBox();
        Random rnd = new Random();
        int plat_index;
        private void Form1_Load(object sender, EventArgs e)
        {
            timer1.Enabled = true;

            mario.Image = Image.FromFile("./mario.jpg");
            mario.SetBounds(40, 259, 40, 60);
            mario.SizeMode = PictureBoxSizeMode.StretchImage;
            Controls.Add(mario);

            for (int i = 0; i < 100; i++)
            {
                brick[i] = new PictureBox();
                brick[i].Size = new Size(0, 0);
                brick[i].Image = Image.FromFile("./brick.png");
                brick[i].SizeMode = PictureBoxSizeMode.StretchImage;
                Controls.Add(brick[i]);
            }
            // Set Ground
            for (int i = 0; i < 17; i++)
            {
                brick[i].SetBounds(40 * i, 319, 40, 40);
            }

            // Set Map (Obstacles & Platforms)
            int obstacle_cnt = 3;
            brick[17].SetBounds(340, 279, 40, 40);
            brick[18].SetBounds(1040, 279, 40, 40);
            brick[19].SetBounds(2000, 279, 40, 40);

            plat_index = 17 + obstacle_cnt;
            int firstPlatNum = 3;
            for (int i = plat_index; i < plat_index + firstPlatNum; i++)
            {
                brick[i].SetBounds(690 + 40 * i, 164, 40, 40);
            }

            plat_index += firstPlatNum;
            int secondPlatNum = 5;
            for (int i = plat_index; i < plat_index + secondPlatNum; i++)
            {
                brick[i].SetBounds(1600 + 40 * (i - 23), 164, 40, 40);
            }

            plat_index += secondPlatNum;
            int thirdPlatNum = 3;
            for (int i = plat_index; i < plat_index + thirdPlatNum; i++)
            {
                brick[i].SetBounds(1840 + 40 * (i - 28), 114, 40, 40);
            }
            plat_index = 17 + obstacle_cnt; //暫且把plat_index設回初始值

        }

        bool jump = false, toLeft = false, toRight = false;
        const int init_velocity = 18;
        int current_velocity = init_velocity;
        bool isRightImage = true;
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {


            if (e.KeyCode == Keys.Up || e.KeyCode == Keys.W)
            {
                if (jump == false)
                {
                    jump = true;
                    if (isRightImage)
                        mario.Image = Image.FromFile("./mario_jump.png");
                    else
                        mario.Image = Image.FromFile("./mario_jump_left.png");
                    current_velocity = init_velocity;
                }
            }
            
            if(e.KeyCode == Keys.Left || e.KeyCode == Keys.A)
            {
                toLeft = true;
                toRight = false;
                mario.Image = Image.FromFile("./mario_left.jpg");
                isRightImage = false;

            }

            if (e.KeyCode == Keys.Right || e.KeyCode == Keys.D)
            {
                toRight = true;
                toLeft = false;
                mario.Image = Image.FromFile("./mario.jpg");
                isRightImage = true;

            }
        }

        bool onceLeft = false, onceRight = false;
        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Left || e.KeyCode == Keys.A)
            {
                toLeft = false;
            }
            if (e.KeyCode == Keys.Right || e.KeyCode == Keys.D)
            {
                toRight = false;
            }
            //未解決馬力歐向左跳著地後圖檔
        }

        bool collided = false;
        bool touched = false;
        private void timer1_Tick(object sender, EventArgs e)
        {
            for (int i = 0; i < 100; i++)
            {
                if (mario.Left - 2 <= brick[i].Right && mario.Left - 2 >= brick[i].Left && mario.Top <= brick[i].Top && mario.Bottom >= brick[i].Bottom)
                    toLeft = false;
            }

            for (int i = 0; i < 100; i++)
            {
                if (mario.Right + 2 >= brick[i].Left && mario.Right + 2 <= brick[i].Right && mario.Top <= brick[i].Top && mario.Bottom >= brick[i].Bottom)
                    toRight = false;
            }

            if (mario.Left < 300)
            {
                if (toLeft)
                {
                    if (mario.Left >= 0)
                        mario.Left -= 2;
                }

                else if (toRight)
                    mario.Left += 2;
            }

            else if (mario.Left >= 300)
            {
                if (toLeft)
                {
                    mario.Left--;
                    for (int i = 0; i < 17; i++)
                    {
                        brick[i].Left++;
                        if (brick[i].Left >= 600)
                            brick[i].Left -= 640;
                    }

                    for (int i = 17; i < 100; i++)
                    {
                        brick[i].Left++;

                        if (brick[i].Left >= 600)
                            brick[i].Dispose();
                    }
                }
                else if (toRight)
                {
                    //mario.Left++;
                    for (int i = 0; i < 17; i++)
                    {
                        brick[i].Left-=2;
                        if (brick[i].Left <= -40)
                            brick[i].Left += 640;
                    }

                    for (int i = 17; i < 100; i++)
                    {
                        brick[i].Left -= 2;

                        if (brick[i].Left <= -40)
                            brick[i].Dispose();
                    }
                }
            }
            for (int i = 0; i < 100; i++)
            {
                //if (i<)
                {

                }
            }


            if (jump)
            {
                if (current_velocity > 0) //上升中
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (mario.Top <= brick[i].Bottom && mario.Bottom > brick[i].Bottom && mario.Left == brick[i].Left) //有撞到磚塊
                        {
                            if (collided == false)
                            {
                                collided = true;
                                current_velocity = 0;
                            }
                        }
                    }
                    current_velocity--;
                    mario.Top -= current_velocity;
                }

                else if (current_velocity <= 0)
                {
                    current_velocity--;
                    mario.Top -= current_velocity;
                    for (int i = 0; i < 100; i++)
                    {
                        if ((mario.Bottom >= brick[i].Top && mario.Left <= brick[i].Right && mario.Right >= brick[i].Left) || mario.Bottom >= 319)  //碰到障礙、平台或地板
                        {
                            collided = false;
                            jump = false;
                            if (isRightImage)
                                mario.Image = Image.FromFile("./mario.jpg");
                            else
                                mario.Image = Image.FromFile("./mario_left.jpg");
                        }
                    }
                }

            }
        }


        int x, y;
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            label1.Text = Convert.ToString(x);
            label2.Text = Convert.ToString(y);
            label3.Text = Convert.ToString(mario.Top);
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            x = e.Location.X;
            y = e.Location.Y;
            this.Invalidate();
        }
    }
}
