using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyLibrary
{
    public class Text
    {
        private MyString[] text;
        private int size;
        public Text()
        {
            text = null;
            size = 0;
        }

        public Text(ref MyString[] str, int size)
        {
            this.size = size;
            this.text = new MyString[size];
            for (int i = 0; i < size; i++)
                this.text[i] = str[i];
        }

        public void AddStr(in MyString str)
        {
            MyString[] copy = Copy();
            size++;
            text = new MyString[size];
            for (int i = 0; i < size - 1; i++)
                text[i] = copy[i];
            text[size - 1] = str;
        }

        public void RemoveStr(int index)
        {
            MyString[] copy = Copy();
            size--;
            index--;
            text = new MyString[size];
            for (int i = 0; i < index; i++)
                text[i] = copy[i];
            for (int i = index; i < size; i++)
                text[i] = copy[i + 1];
        }

        private MyString[] Copy()
        {
            MyString[] text1 = new MyString[size];
            for (int i = 0; i < size; i++)
                text1[i] = text[i];
            return text1;
        }

        public int FullLen()
        {
            int length = 0;
            for (int i = 0; i < size; i++)
                length += text[i].Size();
            return length;
        }

        public void Cout()
        {
            Console.WriteLine("Our lines: ");
            for (int i = 0; i < size; i++)
            {
                text[i].print();
                Console.WriteLine();
            }
        }

        public void DeleteCopyStr(int index)
        {
            if (index >= 0 && size > 1)
            {
                int counter = 0,
                    correction = 0;

                MyString basic = text[index];
                for (int i = 0; i < size; i++)
                {
                    if (i != index && basic.Equation(text[i]))
                        counter++;
                }

                if (counter > 0)
                {
                    MyString[] lines = new MyString[size];
                    for (int j = 0; j < size; j++)
                        lines[j] = text[j];

                    text = new MyString[size - counter];
                    int i = 0,
                        push = 0;
                    while (i < size)
                    {
                        if (i != index && basic.Equation(lines[i]))
                            correction++;
                        else if (push + correction < size)
                        {
                            text[push] = lines[push + correction];
                            push++;
                        }
                        i++;
                    }
                    size = size - counter;
                }
            }
        }

        public void Clear()
        {
            text = null;
            size = 0;
        }
    }
}
