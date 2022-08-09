namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// 設計工具所需的變數。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清除任何使用中的資源。
        /// </summary>
        /// <param name="disposing">如果應該處置 Managed 資源則為 true，否則為 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 設計工具產生的程式碼

        /// <summary>
        /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
        /// 這個方法的內容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.startBtn = new System.Windows.Forms.Button();
            this.restartBtn = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.lifeLbl = new System.Windows.Forms.Label();
            this.scoreLbl = new System.Windows.Forms.Label();
            this.score = new System.Windows.Forms.Label();
            this.life = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // startBtn
            // 
            this.startBtn.Location = new System.Drawing.Point(51, 422);
            this.startBtn.Name = "startBtn";
            this.startBtn.Size = new System.Drawing.Size(75, 23);
            this.startBtn.TabIndex = 0;
            this.startBtn.Text = "start";
            this.startBtn.UseVisualStyleBackColor = true;
            this.startBtn.Click += new System.EventHandler(this.startBtn_Click);
            // 
            // restartBtn
            // 
            this.restartBtn.Location = new System.Drawing.Point(181, 422);
            this.restartBtn.Name = "restartBtn";
            this.restartBtn.Size = new System.Drawing.Size(75, 23);
            this.restartBtn.TabIndex = 1;
            this.restartBtn.Text = "restart";
            this.restartBtn.UseVisualStyleBackColor = true;
            this.restartBtn.Click += new System.EventHandler(this.restartBtn_Click);
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.Color.Black;
            this.button3.Location = new System.Drawing.Point(-2, 370);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(580, 25);
            this.button3.TabIndex = 2;
            this.button3.Text = "button3";
            this.button3.UseVisualStyleBackColor = false;
            // 
            // lifeLbl
            // 
            this.lifeLbl.AutoSize = true;
            this.lifeLbl.Location = new System.Drawing.Point(363, 427);
            this.lifeLbl.Name = "lifeLbl";
            this.lifeLbl.Size = new System.Drawing.Size(20, 12);
            this.lifeLbl.TabIndex = 3;
            this.lifeLbl.Text = "life";
            // 
            // scoreLbl
            // 
            this.scoreLbl.AutoSize = true;
            this.scoreLbl.Location = new System.Drawing.Point(460, 427);
            this.scoreLbl.Name = "scoreLbl";
            this.scoreLbl.Size = new System.Drawing.Size(29, 12);
            this.scoreLbl.TabIndex = 4;
            this.scoreLbl.Text = "score";
            // 
            // score
            // 
            this.score.AutoSize = true;
            this.score.Location = new System.Drawing.Point(506, 427);
            this.score.Name = "score";
            this.score.Size = new System.Drawing.Size(17, 12);
            this.score.TabIndex = 5;
            this.score.Text = "00";
            // 
            // life
            // 
            this.life.AutoSize = true;
            this.life.Location = new System.Drawing.Point(400, 427);
            this.life.Name = "life";
            this.life.Size = new System.Drawing.Size(17, 12);
            this.life.TabIndex = 6;
            this.life.Text = "10";
            // 
            // timer1
            // 
            this.timer1.Interval = 500;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(706, 457);
            this.Controls.Add(this.life);
            this.Controls.Add(this.score);
            this.Controls.Add(this.scoreLbl);
            this.Controls.Add(this.lifeLbl);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.restartBtn);
            this.Controls.Add(this.startBtn);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button startBtn;
        private System.Windows.Forms.Button restartBtn;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Label lifeLbl;
        private System.Windows.Forms.Label scoreLbl;
        private System.Windows.Forms.Label score;
        private System.Windows.Forms.Label life;
        private System.Windows.Forms.Timer timer1;
    }
}

