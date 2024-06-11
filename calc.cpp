#include <cmath>
#include "calc.h"

void _help()
{
    std::cout << "Uso: ./a.out [--parametros] [valor]\n"
                 "\t--dec2bin Para converter decimal para binário.\n"
                 "\t--bin2dec Para converter binário para decimal.\n\n"
                 "\t-f Preenche com zeros a esquerda (somente dec2bin).\n";
}

void _start(int argc, char **argv)
{
    if (argc > 2)
    {
        std::string param = argv[1];
        std::string value = argv[2];
        bool fill = (argc == 4 && (std::string)argv[3] == "-f") ? true : false;
        // debug
        // std::cout << param << "\n";
        // std::cout << value << "\n";

        if (param == "--dec2bin" || param == "-d")
        {
            _dec2bin(std::stoi(value), fill);
        }
        else if (param == "--bin2dec" || param == "-b")
        {
            _bin2dec(value);
        }
        else
        {
            std::cout << "Erro! Parametro desconhecido.\n";
        }
    }
    else
    {
        _help();
    }
}

void _dec2bin(int value, bool fill = false)
{
    int bin_arr[32], i = 0;

    for (int j = 0; j < 32; j++)
    {
        bin_arr[j] = 0;
    }

    while (value > 0)
    {
        bin_arr[i] = value % 2;
        value /= 2;
        i++;
    }

    int counter = i;

    if (fill)
    {
        if (i % 4 != 0)
        {
            int int_i = i / 4;
            int_i += 1;
            counter = int_i * 4;
        }
    }

    for (int k = counter - 1; k >= 0; k--)
    {
        if (k % 4 == 0)
        {
            std::cout << bin_arr[k] << ' ';
        }
        else
        {

            std::cout << bin_arr[k];
        }
    }
    std::cout << '\n';
}

void _bin2dec(std::string value)
{
    unsigned long int dec = 0;

    for (int k = 0; k < value.length(); k++)
    {
        if (value[k] != '0' && value[k] != '1')
        {
            std::cout << "Erro! Binário inválido.\n";
            return;
        }

        int c = value[k] - '0';

        int exp = value.length() - (k + 1);
        dec += c * pow(2, exp);
    }

    std::cout << dec << '\n';
}