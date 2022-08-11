namespace MMXLVIII
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.backBtn = new System.Windows.Forms.Button();
            this.retryBtn = new System.Windows.Forms.Button();
            this.ScoreLbl = new System.Windows.Forms.Label();
            this.Scores = new System.Windows.Forms.Label();
            this.HighScores = new System.Windows.Forms.Label();
            this.HighScoreLbl = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // backBtn
            // 
            this.backBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.backBtn.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.backBtn.Font = new System.Drawing.Font("UD Digi Kyokasho NP-R", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.backBtn.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.backBtn.Location = new System.Drawing.Point(236, 75);
            this.backBtn.Name = "backBtn";
            this.backBtn.Size = new System.Drawing.Size(68, 68);
            this.backBtn.TabIndex = 3;
            this.backBtn.Text = "Back";
            this.backBtn.UseVisualStyleBackColor = false;
            this.backBtn.Click += new System.EventHandler(this.backBtn_Click);
            // 
            // retryBtn
            // 
            this.retryBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.retryBtn.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.retryBtn.Font = new System.Drawing.Font("UD Digi Kyokasho NP-R", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.retryBtn.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.retryBtn.Location = new System.Drawing.Point(354, 75);
            this.retryBtn.Name = "retryBtn";
            this.retryBtn.Size = new System.Drawing.Size(68, 68);
            this.retryBtn.TabIndex = 4;
            this.retryBtn.Text = "Retry";
            this.retryBtn.UseVisualStyleBackColor = false;
            this.retryBtn.Click += new System.EventHandler(this.RetryBtn_Click);
            // 
            // ScoreLbl
            // 
            this.ScoreLbl.AutoSize = true;
            this.ScoreLbl.Font = new System.Drawing.Font("UD Digi Kyokasho NP-R", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.ScoreLbl.Location = new System.Drawing.Point(240, 18);
            this.ScoreLbl.Name = "ScoreLbl";
            this.ScoreLbl.Size = new System.Drawing.Size(61, 20);
            this.ScoreLbl.TabIndex = 5;
            this.ScoreLbl.Text = "Score";
            // 
            // Scores
            // 
            this.Scores.AutoSize = true;
            this.Scores.Font = new System.Drawing.Font("UD Digi Kyokasho NP-R", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.Scores.Location = new System.Drawing.Point(242, 44);
            this.Scores.Name = "Scores";
            this.Scores.Size = new System.Drawing.Size(57, 20);
            this.Scores.TabIndex = 6;
            this.Scores.Text = "0000";
            // 
            // HighScores
            // 
            this.HighScores.AutoSize = true;
            this.HighScores.Font = new System.Drawing.Font("UD Digi Kyokasho NP-R", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.HighScores.Location = new System.Drawing.Point(361, 44);
            this.HighScores.Name = "HighScores";
            this.HighScores.Size = new System.Drawing.Size(57, 20);
            this.HighScores.TabIndex = 8;
            this.HighScores.Text = "0000";
            // 
            // HighScoreLbl
            // 
            this.HighScoreLbl.AutoSize = true;
            this.HighScoreLbl.Font = new System.Drawing.Font("UD Digi Kyokasho NP-R", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.HighScoreLbl.Location = new System.Drawing.Point(316, 18);
            this.HighScoreLbl.Name = "HighScoreLbl";
            this.HighScoreLbl.Size = new System.Drawing.Size(139, 20);
            this.HighScoreLbl.TabIndex = 7;
            this.HighScoreLbl.Text = "Highest Score";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("MV Boli", 36F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(64)))), ((int)(((byte)(0)))));
            this.label2.Location = new System.Drawing.Point(12, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(197, 79);
            this.label2.TabIndex = 9;
            this.label2.Text = "2048";
            this.label2.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.ClientSize = new System.Drawing.Size(466, 518);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.HighScores);
            this.Controls.Add(this.HighScoreLbl);
            this.Controls.Add(this.Scores);
            this.Controls.Add(this.ScoreLbl);
            this.Controls.Add(this.retryBtn);
            this.Controls.Add(this.backBtn);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form2";
            this.Text = "Form2";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form2_FormClosing);
            this.Load += new System.EventHandler(this.Form2_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form2_KeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button backBtn;
        private System.Windows.Forms.Button retryBtn;
        private System.Windows.Forms.Label ScoreLbl;
        private System.Windows.Forms.Label Scores;
        private System.Windows.Forms.Label HighScores;
        private System.Windows.Forms.Label HighScoreLbl;
        private System.Windows.Forms.Label label2;
    }
}