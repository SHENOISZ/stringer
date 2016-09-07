/*
*@AUTHOR SHENOISZ
*https://github.com/SHENOISZ/stringer
*/
#include <sstream>

#define for_each( item, items )\
 for(int i = 0; i <= shenoisz::String::len( items ) + 1; item = items[i], i++)

using namespace std;

namespace shenoisz {


class Util
{

 public:

    Util(int init, int enc, int* array)
    {
        this->init = init;
        this->enc = enc;
        this->array = array;
    }

    int index()
    {
        if (init > -1)
        {
            return init;
        }
        else
        {
            return -1;
        }
    }

     int* indexes()
    {
        if (init > -1)
        {
            return array;
        }
        else
        {
            int *resto = new int[0];
            resto[0] = -1;

            return resto;
        }
    }

    int counter()
    {
        if (init > -1)
        {
            return enc;
        }
        else
        {
            return -1;
        }
    }

    bool exists()
    {
        if (init > -1)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

 private:

    int init;
    int enc;
    int* array;
};

class String
{

 protected:

 public:

    String() {
        // constructor
    }

    ~String() {
        // destructor
    }

    bool exists(string texto, string* r)
    {
        string item;
        bool exist = false;

        for_each(item, r)
        {
            if (item == texto) {
                exist = true;
            }
        }

        return exist;
    }

    string replaceAll(string atual, string novo, string texto)
    {
        int total = texto.length();
        int rm = atual.length();
        int finish = novo.length();

        string temp, nova;

        for (int i = 0; i < total; i++, total = texto.length())
        {
            temp = this->substr(i, i + rm, texto);

            if (temp == atual) {

                nova = this->substr(0, i, texto);
                nova += novo;
                nova += this->substr(i + rm, total, texto);

                texto = nova;
            }
        }

        return nova;
    }

    static string replaceAll(char atual, char replace, string texto)
    {
        for (int i = 0; i < texto.length(); i++)
        {
            if (atual == texto[i])
            {
                texto[i] = replace;
            }
        }

        return texto;
    }

    string replace(string atual, string replace, string texto)
    {
        int total = texto.length();
        int rm = atual.length();
        string temp, nova;

        for (int i = 0; i < total; i++)
        {
            temp = this->substr(i, i + rm, texto);

            if (temp == atual) {

                nova = this->substr(0, i, texto);
                nova += replace;
                nova += this->substr(i + rm, total, texto);
                break;
            }
        }

        return nova;
    }

    static string replace(char atual, char replace, string texto)
    {
        for (int i = 0; i < texto.length(); i++)
        {
            if (atual == texto[i])
            {
                texto[i] = replace;
                break;
            }
        }

        return texto;
    }

    static int length(string texto)
    {
        int i = 0;

        while (true)
        {
            if (texto[i] == '\0')
            {
                i--;
                break;

            } else
            {
                i++;
            }
        }

        return i;
    }


    static int len(int* nuns)
    {
        int i = 0;
        bool scape = false;

        if (nuns[0] == 0)
        {
            nuns[0] = 1;
            scape = true;
        }

        while (true)
        {
            if (nuns[i] == -1)
            {
                i--;
                break;

            } else
            {
                if (scape)
                {
                    nuns[0] = 0;
                    scape = false;
                }

                i++;
            }
        }

        return i;
    }

    static int len(string* texto)
    {
        int i = 0;

        while (true)
        {
            if (texto[i] == "NULL")
            {
                i--;
                break;

            } else
            {
                i++;
            }
        }

        return i;
    }

    static int charCount(char item, string texto)
    {
        int n = -1;

        for (int i = 0; i < texto.length(); i++)
        {
            if (item == texto[i])
            {
                n++;
            }
        }

        return n;
    }

    static int* charMap(char item, string texto)
    {
        int *n = new int[String::charCount(item, texto) + 1];
        int count = 0;

        for (int i = 0; i < texto.length(); i++)
        {
            if (item == texto[i])
            {
                n[count] = i;
                count++;
            }
        }

        n[count] = -1;

        return n;
    }

    static string* split(string item, string texto)
    {
        int init = 0, n = 0;
        int* map = String::find(item, texto)->indexes();
        int size = String::len(map) + 1;

        string *arr = new string[size + 2];

        for (int i = 0; i <= size; i++)
        {
            if (i == size) map[i] = texto.length();

            arr[i] = String::substr(init, map[i], texto);

            init = map[i] + item.length();
            n++;
        }

        arr[n] = "NULL";

        return arr;
    }

    static string* split(char item, string texto)
    {
        int init = 0, n = 0;
        int* map = String::charMap(item, texto);
        int size = String::len(map) + 1;

        string *arr = new string[size + 2];

        for (int i = 0; i <= size; i++)
        {
            if (i == size) map[i] = texto.length();

            arr[i] = String::substr(init, map[i], texto);

            init = map[i] + 1;
            n++;
        }

        arr[n] = "NULL";

        return arr;
    }

    static string substr(int start, int end, string texto)
    {
        string nova;
        int total = texto.length(), i = 0;

        (start > total) ? i = total : i = start;
        (end > total) ? end = total : end;

        for ( ; i < end; i++)
        {
            nova += texto[i];
        }

        return nova;
    }

    static Util* find(char cc, string texto)
    {
        string src;
        src = cc;
        int total = texto.length();
        int src_ = src.length();
        int found = 0, index = 0;

        int *map = new int[(total / src_) + 1];
        string temp;

        bool finded = true;

        for (int i = 0; i < total; i++)
        {
            temp = String::substr(i, i + src_, texto);

            if (temp == src) {

                map[found] = i;

                if (finded)
                {
                    index = i;
                    finded = false;
                }

                found++;
            }
        }

        map[found] = -1;

        return new Util(index, String::len(map), map);
    }

    static Util* find(string src, string texto)
    {
        int total = texto.length();
        int src_ = src.length();
        int found = 0, index = 0;

        int *map = new int[(total / src_) + 1];
        string temp;

        bool finded = true;

        for (int i = 0; i < total; i++)
        {
            temp = String::substr(i, i + src_, texto);

            if (temp == src) {

                map[found] = i;

                if (finded)
                {
                    index = i;
                    finded = false;
                }

                found++;
            }
        }

        map[found] = -1;

        return new Util(index, String::len(map), map);
    }

    static string format(string texto, string array[])
    {
        string nova;
        String *str = new String;

        for (int i = 0; i <= String::len(array); i++)
        {
            nova = str->replace("{" + String::toString(i) + "}", array[i], texto);
            texto = nova;
        }

        return texto;
    }

    static string toString(double num)
    {
        stringstream i;
        i << num;

        return i.str();
    }

    static string toString(float num)
    {
        stringstream i;
        i << num;

        return i.str();
    }

    static string toString(int num)
    {
        stringstream i;
        i << num;

        return i.str();
    }

    static string toString(char cc)
    {
        string letra;

        letra = cc;

        return letra;
    }

    static int toInt(string texto)
    {
        int value;

        istringstream s(texto);
        s >> value;

        return value;
    }

    static float toFloat(string texto)
    {
        float value;

        istringstream s(texto);
        s >> value;

        return value;
    }

    static double toDouble(string texto)
    {
        double value;

        istringstream s(texto);
        s >> value;

        return value;
    }

 private:

} str;

}