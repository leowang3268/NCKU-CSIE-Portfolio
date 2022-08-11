namespace Minesweeper
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            this.time_lbl = new System.Windows.Forms.Label();
            this.flag_lbl = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.Retry_Btn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // time_lbl
            // 
            this.time_lbl.AutoSize = true;
            this.time_lbl.Font = new System.Drawing.Font("PMingLiU", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.time_lbl.Location = new System.Drawing.Point(875, 70);
            this.time_lbl.Name = "time_lbl";
            this.time_lbl.Size = new System.Drawing.Size(53, 20);
            this.time_lbl.TabIndex = 0;
            this.time_lbl.Text = "label1";
            // 
            // flag_lbl
            // 
            this.flag_lbl.AutoSize = true;
            this.flag_lbl.Font = new System.Drawing.Font("PMingLiU", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.flag_lbl.Location = new System.Drawing.Point(875, 141);
            this.flag_lbl.Name = "flag_lbl";
            this.flag_lbl.Size = new System.Drawing.Size(53, 20);
            this.flag_lbl.TabIndex = 1;
            this.flag_lbl.Text = "label1";
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Retry_Btn
            // 
            this.Retry_Btn.Font = new System.Drawing.Font("PMingLiU", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.Retry_Btn.Location = new System.Drawing.Point(875, 237);
            this.Retry_Btn.Name = "Retry_Btn";
            this.Retry_Btn.Size = new System.Drawing.Size(90, 37);
            this.Retry_Btn.TabIndex = 2;
            this.Retry_Btn.Text = "Retry";
            this.Retry_Btn.UseVisualStyleBackColor = true;
            this.Retry_Btn.Click += new System.EventHandler(this.Retry_Btn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1082, 803);
            this.Controls.Add(this.Retry_Btn);
            this.Controls.Add(this.flag_lbl);
            this.Controls.Add(this.time_lbl);
            this.ForeColor = System.Drawing.SystemColors.ControlText;
            this.Name = "Form1";
            this.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label time_lbl;
        private System.Windows.Forms.Label flag_lbl;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button Retry_Btn;
    }
}

