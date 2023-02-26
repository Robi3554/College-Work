namespace Lab_1
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
            this.bot = new System.Windows.Forms.Label();
            this.boy = new System.Windows.Forms.Label();
            this.UtilText = new System.Windows.Forms.TextBox();
            this.PassText = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // bot
            // 
            this.bot.AutoSize = true;
            this.bot.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bot.Location = new System.Drawing.Point(78, 84);
            this.bot.Name = "bot";
            this.bot.Size = new System.Drawing.Size(76, 20);
            this.bot.TabIndex = 0;
            this.bot.Text = "Utilizator";
            // 
            // boy
            // 
            this.boy.AutoSize = true;
            this.boy.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.boy.Location = new System.Drawing.Point(82, 144);
            this.boy.Name = "boy";
            this.boy.Size = new System.Drawing.Size(57, 20);
            this.boy.TabIndex = 1;
            this.boy.Text = "Parola";
            // 
            // UtilText
            // 
            this.UtilText.Location = new System.Drawing.Point(340, 82);
            this.UtilText.Name = "UtilText";
            this.UtilText.Size = new System.Drawing.Size(222, 22);
            this.UtilText.TabIndex = 2;
            // 
            // PassText
            // 
            this.PassText.Location = new System.Drawing.Point(340, 153);
            this.PassText.Name = "PassText";
            this.PassText.Size = new System.Drawing.Size(222, 22);
            this.PassText.TabIndex = 3;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(340, 277);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(190, 75);
            this.button1.TabIndex = 4;
            this.button1.Text = "Autentificare";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.PassText);
            this.Controls.Add(this.UtilText);
            this.Controls.Add(this.boy);
            this.Controls.Add(this.bot);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label bot;
        private System.Windows.Forms.Label boy;
        private System.Windows.Forms.TextBox UtilText;
        private System.Windows.Forms.TextBox PassText;
        private System.Windows.Forms.Button button1;
    }
}

