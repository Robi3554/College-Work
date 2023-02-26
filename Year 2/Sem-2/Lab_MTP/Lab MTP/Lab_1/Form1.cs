using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (UtilText.Text == "Robert" && PassText.Text == "Parola")
            {
                Form form = new Form2();
                form.ShowDialog();
            }
            else
            {
                MessageBox.Show("Utilizator/Parola Incorecta!");
            }
        }
    }
}
