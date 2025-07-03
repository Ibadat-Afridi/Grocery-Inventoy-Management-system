#include <stdio.h>
#include <string.h>

int admin_login();

//Structure for username and password
struct credentials
{
    //string declared for admins credentials
    char uname[7];
    char upassword[6];
};
int admin_login()
{
    //creating instances for two admins
    struct credentials cred1, cred2;
    //putting the credential username and password in the structure variables using strcpy() string function which take two arguments 1 is variable and another is content
    strcpy(cred1.uname, "ibadat"); 
    strcpy(cred1.upassword, "12345");
    strcpy(cred2.uname, "habib");
    strcpy(cred2.upassword, "67890");
    //declaring another two variables by which we can get inputs from the admin
    char username[7];
    char pass[6];
    //loop running four times
    for (int i = 1; i <= 4; i++)
    {
        //taking admin username and admin password as input
        printf("Enter admin username: ");
        scanf("%6s", username);
        printf("Enter admin password: ");
        scanf("%5s", pass);
        //Checking the admin attempting the password wrong many times 
        if (i == 4)
        {
            printf("You tried several times and make invalid credentials so your account session has been blocked\n");
            return 0;
            break;
        }
        //verifying the admins by using the strcmp function which compare the ASCII Code
        if ((strcmp(username, cred1.uname) == 0 && strcmp(pass, cred1.upassword) == 0) || (strcmp(username, cred2.uname) == 0 && strcmp(pass, cred2.upassword) == 0))
        {
            printf("Access Granted to Admin Panel\n");
            return 1;
            break;
        }
        //In case of wrong credentials inputed on each iteration the below else will be executed
        else
        {
            printf("Wrong Credentials, Please try again!\n");
        }
    }
    return 0;
}
