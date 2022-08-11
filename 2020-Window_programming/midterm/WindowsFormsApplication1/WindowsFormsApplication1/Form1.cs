using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        //考後檢討: restart時要將timer1的interval再設為500
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            
            restartBtn.Enabled = false;
            life.Text = "10";
        }

        private void startBtn_Click(object sender, EventArgs e)
        {
            this.KeyPreview = true;
            timer1.Enabled = true;
            startBtn.Enabled = false;
            restartBtn.Enabled = true;

        }

        List<Button> button = new List<Button>();

        bool lose = false;
        private void timer1_Tick(object sender, EventArgs e)
        {
            Button tmpBtn = new Button();
            Random rnd_x = new Random();
            int pos_x = rnd_x.Next(20, 600);
            tmpBtn.SetBounds(pos_x, 0, 30, 30);
            Random rnd_alphabet = new Random();
            int index = rnd_alphabet.Next(0, 26);
            char ch = Convert.ToChar(65 + index); 
            tmpBtn.Text = $"{ch}";
            Controls.Add(tmpBtn);
            button.Add(tmpBtn);
            for (int i = 0; i < button.Count; i++)
            {
                if(button[i].Visible==true)
                    button[i].Top += 10;
            }

            lose = isLose();
            if (lose == true)
            {
                timer1.Enabled = false;
                timer1.Stop();
                MessageBox.Show($"Get {Convert.ToInt32(score.Text)} points");
                restartBtn_Click(sender, e);
                score.Text = "0";
                for (int i = 0; i < button.Count; i++)
                {
                    button[i].Dispose();
                    button[i].Visible = false;
                    button[i].Enabled = false;
                }
               

            }

        }

        

        private void restartBtn_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < button.Count; i++)
            {
                button[i].Visible = false;
            }
            score.Text = "00";
            life.Text = "10";
            timer1.Enabled = false;
            startBtn.Enabled = true;
        }

        int score_value = 0;
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            for (int i = 0; i < button.Count; i++)
            {
                if (button[i].Text == e.KeyCode.ToString() && button[i].Visible==true)
                {
                    //button.RemoveAt(i);
                    button[i].Visible = false;
                    button[i].Dispose();
                    score_value++;
                    score.Text = score_value.ToString();
                    if (timer1.Interval > 50)
                        timer1.Interval -= 50;
                    break;
                    
                }
            }
        }

        private bool isLose()
        {
            for (int i = 0; i < button.Count; i++)
            {
                if (button[i].Bottom == button3.Top && button[i].Visible == true)
                {
                    life.Text = (Convert.ToInt32(life.Text) - 1).ToString();
                    button[i].Visible = false;
                }
                    
                    
                if (Convert.ToInt32(life.Text) == 0)
                    return true;              
            }
            return false;
        }

    }
}
