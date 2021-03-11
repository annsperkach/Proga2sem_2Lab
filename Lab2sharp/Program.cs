using System;
using MyLibrary;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba2
{
    class Program
    {
        static void Main(string[] args)
        {
            int size = 0;
            Text text = new Text();
            while (size <= 0)
            {
                Console.WriteLine("How many lines? ");
                string size1 = Console.ReadLine().ToString();
                size = int.Parse(size1);
                if (size != (int)size)
                {
                    size = 0;
                }
            }

            string str;
            for (int i = 0; i < size; i++)
            {
                str = Console.ReadLine();
                char[] arr = new char[str.Length + 1];
                arr = str.ToCharArray();
                MyString str1 = new MyString(arr);
                text.AddStr(in str1);
            }
            menu(ref text);
        }
        static void menu(ref Text text)
        {
            int temp = 0;
            bool flag = true;
            Console.WriteLine("1 - add line");
            Console.WriteLine("2 - delete the line");
            Console.WriteLine("3 - delete copies");
            Console.WriteLine("4 - frequency of the lines");
            Console.WriteLine("5 - clear the text");
            Console.WriteLine("6 - menu");
            Console.WriteLine("7 - finish the program");
            while (flag)
            {
                char[] temp1 = new char[30];
                while (temp <= 7)
                {
                    string temp2 = Console.ReadLine().ToString();
                    temp = int.Parse(temp2);
                    if (temp != (int)temp)
                    {
                        temp = 0;
                    }
                    else { break; }
                }
                if (temp == 1)
                {
                    string str1;
                    Console.WriteLine("write the line to add:");
                    str1 = Console.ReadLine();
                    char[] arr = new char[str1.Length + 1];
                    arr = str1.ToCharArray();
                    MyString str = new MyString(arr);
                    text.AddStr(in str);
                    text.Cout();
                }
                else if (temp == 2)
                {
                    int index = 0;
                    char[] temp2 = new char[30];
                    while (index <= 0)
                    {
                        Console.WriteLine("write the line to delete:");
                        index = int.Parse(Console.ReadLine());
                        if (index != (int)index)
                        {
                            index = 0;
                        }
                    }
                    text.RemoveStr(index);
                    text.Cout();
                }
                else if (temp == 3)
                {
                    Console.WriteLine("delete the dublicates:");
                    text.DeleteCopyStr(0);
                    text.Cout();
                }
                else if (temp == 4)
                {
                    int length = text.FullLen();
                    Console.WriteLine("frequency of the line:" + length);
                    text.Cout();
                    text.FullLen();
                }
                else if (temp == 5)
                {
                    text.Clear();
                    text.Cout();
                }
                else if (temp == 6)
                {
                    Console.WriteLine("1 - add line");
                    Console.WriteLine("2 - delete the line");
                    Console.WriteLine("3 - delete copies");
                    Console.WriteLine("4 - frequency of the lines");
                    Console.WriteLine("5 - clear the text");
                    Console.WriteLine("6 - menu");
                    Console.WriteLine("7 - finish the program");
                }
                else if (temp == 7)
                {
                    flag = false;
                }
            }
        }
    }
}
