using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyLibrary
{
    public class MyString
    {
        private char[] str;
        private int len;
        public MyString()
        {
            str = null;
            len = 0;
        }
        public MyString(in char[] str)
        {
            string temp = new string(str);
            len = temp.Length;
            this.str = new char[len + 1];
            for (int i = 0; i < len; i++)
            {
                this.str[i] = Convert.ToChar(str[i]);
            }
            this.str[len] = '\0';
        }

        public MyString(in MyString other)
        {
            string temp = other.ToString();
            len = temp.Length;
            this.str = new char[len + 1];

            for (int i = 0; i < len; i++)
            {
                this.str[i] = other.str[i];
            }
            this.str[len] = '\0';
        }

        public bool Equation(in MyString other)
        {
            if (len == other.len)
            {
                for (int i = 0; i < len; i++)
                {
                    if (str[i] != other.str[i])
                        return false;
                }
                return true;
            }
            else
                return false;
        }

        public void print()
        {
            Console.Write(str);
        }

        public int Size()
        {
            return len;
        }
    }
}
