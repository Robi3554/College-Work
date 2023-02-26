using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tema1_Lab1
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

        public static string NumberToWords(int number)
        {
            if (number == 0)
                return "zero";

            if (number < 0)
                return "minus " + NumberToWords(Math.Abs(number));

            string words = "";

            if ((number / 1000000) > 0)
            {
                words += NumberToWords(number / 1000000) + " million ";
                number %= 1000000;
            }

            if ((number / 1000) > 0)
            {
                words += NumberToWords(number / 1000) + " thousand ";
                number %= 1000;
            }

            if ((number / 100) > 0)
            {
                words += NumberToWords(number / 100) + " hundred ";
                number %= 100;
            }

            if (number > 0)
            {
                if (words != "")
                    words += "and ";

                var unitsMap = new[] { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
                var tensMap = new[] { "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

                if (number < 20)
                    words += unitsMap[number];
                else
                {
                    words += tensMap[number / 10];
                    if ((number % 10) > 0)
                        words += "-" + unitsMap[number % 10];
                }
            }

            return words;
        }



        private void SalBox_textChanged(object sender, EventArgs e)
        {
            if (!System.Text.RegularExpressions.Regex.IsMatch(SalBox.Text, @"^[0-9]*$"))
            {
                MessageBox.Show("Introduceti o suma corecta!");
                SalBox.Text = SalBox.Text.Remove(SalBox.Text.Length - 1);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string salariu = SalBox.Text;

            float sal_num = (float)Convert.ToDouble(salariu);

            float cfs_angajat = (sal_num / 1000) * 5;

            float cas_angajat = (sal_num / 1000) * 105;

            float cass_angajat = (sal_num / 1000) * 55;

            float imp_angajat = ((sal_num - cfs_angajat - cas_angajat - cass_angajat - 180) / 1000) * 160;

            float cas_angajator = (sal_num / 1000) * 208;

            float cfs_angajator = (sal_num / 1000) * 50;

            float cfci = (sal_num / 1000) * 85;

            float cfgpcs = (sal_num / 1000) * 25;

            float cass_angajator = (sal_num / 10000) * 52;

            float cfambp = (sal_num / 1000) * 4;

            float sal_net = (sal_num - (cfs_angajat + cass_angajat + cas_angajat));

            label14.Text = cfs_angajat.ToString();
            label15.Text = cas_angajat.ToString();
            label16.Text = cass_angajat.ToString();
            label17.Text = imp_angajat.ToString();
            label18.Text = cas_angajator.ToString();
            label19.Text = cfs_angajator.ToString();
            label20.Text = cfci.ToString();
            label21.Text = cfgpcs.ToString();
            label22.Text = cass_angajator.ToString();
            label23.Text = cfambp.ToString();
            label25.Text = sal_net.ToString();

            int sall = (int)sal_num;

            MessageBox.Show(NumberToWords(sall));
        }
    }
}
