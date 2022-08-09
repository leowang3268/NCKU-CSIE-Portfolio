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

namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    { 
        //考後檢討:建立StreamReader時裡面的參數是openFileDialog1.FileName才對
        public Form1()
        {
            InitializeComponent();
        }

        private void 開啟檔案ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                textBox1.Text = "";
                textBox1.Font = oldfnt;
                textBox1.ForeColor = oldclr;
                button1.Font = btn1_fnt;
                button1.ForeColor = btn1_clr;
                button2.Font = btn2_fnt;
                button2.ForeColor = btn2_clr;
                StreamReader sr = new StreamReader(Application.ExecutablePath);  
                string data;
                while (true)
                {
                    data = sr.ReadLine();
                    if (data == null) break;
                    textBox1.Text += data+"\r\n";
                }
                
            }
        }

        private void 字型ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (fontDialog1.ShowDialog() == DialogResult.OK)
            {
                oldfnt = textBox1.Font;
                textBox1.Font = fontDialog1.Font;
            }
        }

        private void 顏色ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {

                oldclr = textBox1.ForeColor;
                textBox1.ForeColor = colorDialog1.Color;
            }
        }
        Color btn1_clr, btn2_clr, oldclr, clr1, clr2; Font btn1_fnt, btn2_fnt, oldfnt, fnt1, fnt2;

        private void 測試字串改模式AToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textBox1.Font = fnt1;
            textBox1.ForeColor = clr1;
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            textBox1.Font = fnt2;
            textBox1.ForeColor = clr2;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            
            btn1_fnt = button1.Font;
            btn1_clr = button1.ForeColor;
            button1.Font = textBox1.Font;
            button1.ForeColor = textBox1.ForeColor;
            clr1 = textBox1.ForeColor;
            fnt1 = textBox1.Font;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            oldfnt = textBox1.Font;
            oldclr = textBox1.ForeColor;
            btn2_fnt = button2.Font;
            btn2_clr = button2.ForeColor;
            button2.Font = textBox1.Font;
            button2.ForeColor = textBox1.ForeColor;
            clr2 = textBox1.ForeColor;
            fnt2 = textBox1.Font;
        }
    }
}
