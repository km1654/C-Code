


//string compute_cipher(string plaintext);
char alphaupper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char alphalower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(int argc, string argv[])
{
    // Get the key
    if(argc < 2 || argc > 2)
    {
        printf("Error\n");
        return(1);
    }

    int string_length = 0;

    for(int i = 0; i < strlen(argv[i]); i++)
    {
         string_length += 1;
    }

    if(string_length < 26)
    {
         printf("Error\n");
         return(1);
    }

    // for(int i = 0; i < string_length; i++)
    // {
    //     //if(argv[i] < A || argv[i] > Z && argv[i] < a || argv[i] > z);
    //     //if(isupper(argv[i]) || islower(argv[i]))
    //     if(!isupper(argv[i]) || !islower(argv[i]))
    //     {
    //         return(0);
    //     }
    //     else
    //     {
    //         printf("Error\n");
    //         return(1);
    //     }

    // }

    // string plaintext = get_string("Plaintext: \n");

    // int length = strlen(plaintext);
    // string ciphertext;

    // for(int i = 0; i < length; i++)

    // if(islower(plaintext[i]))
    // {
    //     ciphertext[i] = alphalower[argv[plaintext[i]]]
    // }
    // if(isupper(plaintext[i]))
    // {
    //     ciphertext[i] = alphaupper[argv[plaintext[i]]]
    // }
    // else
    // {
    //     ciphertext[i] = plaintext[i];
    // }



    // printf("Ciphertext: %s\n", ciphertext);


//string compute_cipher(string plaintext)
}
