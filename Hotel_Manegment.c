#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void total_amt(int price, int time, int qty)
{
    printf("Total Amt.:%d\n\n", price * time * qty);
}
void room(int qty, int i)
{
    srand(time(0));
    for (i = 1; i <= qty; i++)
    {
        int random_num = rand() % 510;
        printf("Room No. : %d\n", random_num);
    }
}

void payment(char upi_id[50], char debit_card[20], char credit_card[20], char password_banking[50], char user_id[50], int payment_type, int card, int pin, int lenght_card, int price, int time, int qty, int i, int room_n)
{
    lenght_card = 0;

    while (1)
    {

        printf("Payment method\n1.UPI Payment\n2.Card Payment\n3.Banking Channel\n4.Case\\Offline\n>");
        scanf("%d", &payment_type);
        if (payment_type == 1)
        {
            while (1)
            {
                printf("UPI Payment\n");
                printf("UPI ID [ok,paytm,etc]:");
                scanf("%s", upi_id);

                if (strstr(upi_id, "@") != 0)
                {
                    printf("Valid UPI Id\n");

                    printf("Pay bill\n");
                    total_amt(price, time, qty);
                    printf("Enter Pin No.:");
                    scanf("%d", &pin);
                    printf("\nSecessfull Payment\n");
                    room(qty, room_n);

                    break;
                }
                else
                {
                    printf("Invalid UPI Id\n");
                }
            }
        }

        if (payment_type == 2)
        {
            while (1)
            {
                printf("Card Payment\n");
                printf("1.Debit Card\n2.Credit Card\n>");
                scanf("%d", &card);

                if (card == 1)
                {
                    printf("Debit card No.:");
                    scanf("%s", debit_card);
                    lenght_card = strlen(debit_card);
                    if (lenght_card == 16)
                    {
                        printf("Valid Card No\n");
                        printf("Pay bill\n");
                        total_amt(price, time, qty);
                        printf("Enter Pin No.:");
                        scanf("%d", &pin);
                        printf("\nSecessfull Payment\n");
                        room(qty, room_n);
                        break;
                    }
                    else
                    {
                        printf("Invalid enter 16 digit No\n");
                    }
                }
                else if (card == 2)
                {
                    printf("Credit card No.:");
                    scanf("%s", credit_card);
                    lenght_card = strlen(credit_card);
                    if (lenght_card == 16)
                    {
                        printf("Valid Card No\n");
                        printf("Pay bill\n");
                        total_amt(price, time, qty);
                        printf("Enter Pin No.:");
                        scanf("%d", &pin);
                        printf("\nSecessfull Payment\n");
                        room(qty, room_n);
                        break;
                    }
                    else
                    {
                        printf("Invalid enter 16 digit No.\n");
                    }
                }
            }
        }

        if (payment_type == 3)
        {
            printf("\t\t\t\t\t\tBanking Channel\n");
            printf("Net Banking\n");
            printf("User ID:");
            scanf("%s", user_id);
            printf("Password:");
            scanf("%s", password_banking);
            printf("Secessful Login\n");
            printf("Pay bill\n");
            total_amt(price, time, qty);
            printf("Enter Pin No.:");
            scanf("%d", &pin);
            printf("\nSecessfull Payment\n");
            room(qty, room_n);
        }

        if (payment_type == 4)
        {
            printf("Case\\Offline\n");
            room(qty, room_n);
        }
        break;
    }
}

int main()
{
    char name[25], email_save[100], country[40], phone[11];
    char state[37][40] = {"Select State", "1.Andhra Pradesh", "2.Arunachal Pradesh", "3.Assam", "4.Bihar", "5.Chhattisgarh", "6.Goa", "7.Gujarat", "8.Haryana", "9.Himachal Pradesh", "10.Jharkhand", "11.Karnataka", "12.Kerala", "13.Madhya Pradesh", "14.Maharashtra", "15.Manipur", "16.Meghalaya", "17.Mizoram", "18.Nagaland", "19.Odisha", "20.Punjab", "21.Rajasthan", "22.Sikkim", "23.Tamil Nadu", "24.Telangana", "25.Tripura", "26.Uttar Pradesh", "27.Uttarakhand", "28.West Bengal", "29.Andaman and Nicobar Islands", "30.Chandigarh", "31.Dadra and Nagar Haveli", "32.Daman and Diu", "33.Jammu Kashmir", "34.Lakshadweep", "35.Delhi National Capital Territory", "36.Puducherry"};
    char save_password[100], enter_password[100], email_enter[100];
    char upi_id[50], debit_card[20], credit_card[20], password_banking[50], user_id[50]; // payment
    int service, enquiry;
    int len = 0;
    int gender, book_room, price, time;
    int qty, room_n, random_num, exit;
    int payment_type, card, pin; // payment
    int lenght_card = 0;         // payment

    //----------------------Home Page------------------------

    while (1)
    {

        printf("\n\t\t\t\t\t\tHOTEL MANEGMENT\n");
        printf("Name :");
        scanf("%s", name);
        printf("\t\t\t\t\t\tWelcome %s\n", name);
        printf("Services \n1.Enquiry\n2.Room Booking\n3.About our Hotel\n");
        printf("Select :");
        scanf("%d", &service);

        if (service == 1)
        {
            printf("\t\t\t\t\t\tEnquiry\n");
            printf("1.Heritage Rooms\n2.Premier Rooms\n3.Deluxe Suite with living room\n4.Luxury Suite with living room\n5.Lutyens Suite\nSelect Option :");
            scanf("%d", &enquiry);

            if (enquiry == 1)
            {
                printf("\t\t\t\t\t\tHERITAGE ROOM\n");

                printf("Built over a hundred years ago, these room are 33 to 42 square meters with King or Twin Bed, housed in the Heritage wing of Maidens Hotel, a few steps away from the swimming pool. The two corridors of the Heritage wing, facing each other, enjoy a picturesque view of the Garden Terrace, with its lush greenery and the most venerated, 150 years old Banyan Tree. Every room in the Heritage wing breathes a scent of the colonial era as high ceilings and the classic furniture of these spacious rooms are bound to captivate your attention.\n");
            }
            else if (enquiry == 2)
            {
                printf("\t\t\t\t\t\tPREMIER ROOM\n");
                printf("While retaining the quaint charm of 19th century, Premier Rooms are newly redesigned and refurbished. Ranging between 37 to 46 square metres in size, with King or Twin bed, featuring wooden flooring, walk-in wardrobe, 4 fixture luxurious Italian marble bathroom with full size tub and walk-in shower, Premier Rooms offer the utmost comfort\n");
            }
            else if (enquiry == 3)
            {
                printf("\t\t\t\t\t\tDELUXE SUITE WITH LIVING ROOM\n");
                printf("The grace and elegance of yester years can be found in these generously spaced suites, ranging between 65 to 75 square metres in size. Comprising two bays, a spacious bedroom and a drawing room, the Deluxe Suite features wooden flooring and is well appointed with all contemporary facilities like a walk-in wardrobe, 4 fixture luxurious Italian marble bathroom with full size tub and walk-in shower.\n");
            }
            else if (enquiry == 4)
            {
                printf("\t\t\t\t\t\tLUXURY SUITE WITH LIVING ROOM\n");
                printf("The magnificent past comes alive through the carefully crafted pieces of furniture, large windows and high ceilings. Ranging between 84 to 130 square metres in size, the Luxury Suite features a spacious bedroom, a grand drawing room, wooden flooring, walk-in wardrobe, 4 fixture Italian marble bathroom with full size tub and walk-in shower.\n");
            }
            else if (enquiry == 5)
            {
                printf("\t\t\t\t\t\tLUTYENS SUITE\n");
                printf("It was from this historic abode that Sir Edwin Lutyens set out to build New Delhi, a new capital for the British Empire’s jewel with the aim to create a garden city 'with room for endless expansion'. The city's spacious core of immaculately designed and executed landmark government and civic buildings made New Delhi arguably the most successful planned city of the 20th century with Lutyens' masterpiece, Viceroys House (Rashtrapati Bhawan) at its heart. The Lutyens Suite features wooden flooring with a grand bedroom, walk-in wardrobe, dressing area and a 4 fixture luxurious Italian marble bathroom with full size tub & walk-in shower. A living room and private terrace surrounded by immaculately manicured greens is the highlight of this most spacious suite (124.2 square metres), meant for those who settle for nothing but the best.\n");
            }
        }
        //--------------------------room booking-----------------------

        else if (service == 2)
        {
            printf("\n\t\t\t\t\t\tBOOKING ROOM\n");
            printf("\nName*:%s\n", name);

            while (1)
            {
                printf("Phone*:");
                scanf("%s", phone);
                len = strlen(phone);
                if (len == 10)
                {
                    printf("Valid Number\n");
                    break;
                }
                else
                {
                    printf("Invalid Number\n");
                }
            }

            printf("\nGender* \n1.Male\t2.Female\t3.Other :");
            scanf("%d", &gender);

            switch (gender)
            {
            case 1:
                printf("Male\n");
                break;

            case 2:
                printf("Female\n");
                break;

            case 3:
                printf("Other\n");
                break;

            default:
                printf("Invalid choise");
                break;
            }

            while (1)
            {
                printf("\nEmail*:");
                scanf("%s", email_save);

                if (strstr(email_save, "@gmail.com") != 0)
                {
                    printf("Valid email\n");
                    break;
                }
                else
                {
                    printf("Invalid email try again!\n");
                }
            }

            printf("\nCountry*:");
            scanf("%s", country);
            int i;
            for (i = 0; i < 36; i++)
            {
                printf("%s\n", state[i]);
            }

            printf("\nEnter State:");
            scanf("%d", &i);
            printf("\n%s\n", state[i]);

            printf("Enter Password :");
            scanf("%s", save_password);

            printf("\n\t\t\t\t\t\tSucessful registration");

            //----------------------------- Login page ---------------------------------------
            printf("\n\n\t\t\t\t\t\t****** Login ******");

            //--------------------email Verification--------------------------
            while (1)
            {
                printf("\nEmail* :");
                scanf("%s", email_enter);

                if (strcmp(email_enter, email_save) == 0)
                {
                    printf("Valid Email!");
                    break;
                }
                else
                {
                    printf("Invalid Email try again !");
                }
            }
            //--------------------password Verification--------------------------
            while (1)
            {

                printf("\n\nPassword* :");
                scanf("%s", enter_password);
                if (strcmp(enter_password, save_password) == 0)
                {
                    printf("Valid Password");
                    printf("\n\n\tSucessfull Login");
                    break;
                }
                else
                {
                    printf("Invalid Password try again !");
                }
            }

            printf("\n\nSelect Room\n1.Heritage Rooms\n2.Premier Rooms\n3.Deluxe Suite with living room\n4.Luxury Suite with living room\n5.Lutyens Suite");
            printf("\nEnter Room :");
            scanf("%d", &book_room);

            if (book_room == 1)
            {
                printf("\t\t\t\t\t\tHeritage Room\n");

                price = 200;
                printf("\nPrice per hour:%d\n", price);
                printf("Enter hour:");
                scanf("%d", &time);
                printf("Number of Rooms:");
                scanf("%d", &qty);
                total_amt(price, time, qty);
                payment(upi_id, debit_card, credit_card, password_banking, user_id, payment_type, card, pin, lenght_card, price, time, qty, i, room_n);
            }

            if (book_room == 2)
            {
                printf("\t\t\t\t\t\tPremir Room\n");

                price = 300;
                printf("Price per hour:%d\n", price);
                printf("Enter hour:");
                scanf("%d", &time);
                printf("Number of Rooms:");
                scanf("%d", &qty);

                total_amt(price, time, qty);
                payment(upi_id, debit_card, credit_card, password_banking, user_id, payment_type, card, pin, lenght_card, price, time, qty, i, room_n);
            }

            if (book_room == 3)
            {
                printf("\t\t\t\tDeluxe Suite with living room\n");

                price = 400;
                printf("\nPrice per hour:%d\n", price);
                printf("Enter hour:");
                scanf("%d", &time);
                printf("Numbers of Rooms:");
                scanf("%d", &qty);

                total_amt(price, time, qty);
                payment(upi_id, debit_card, credit_card, password_banking, user_id, payment_type, card, pin, lenght_card, price, time, qty, i, room_n);
            }

            if (book_room == 4)
            {
                printf("\t\t\t\tLuxury Suite with living room\n");

                price = 500;
                printf("\nPrice per hour:%d\n", price);
                printf("Enter hour:");
                scanf("%d", &time);
                printf("Number of Rooms:");
                scanf("%d", &qty);
                total_amt(price, time, qty);
                payment(upi_id, debit_card, credit_card, password_banking, user_id, payment_type, card, pin, lenght_card, price, time, qty, i, room_n);
            }

            if (book_room == 5)
            {
                printf("\t\t\t\t\t\tLutyens Suite\n");

                price = 600;
                printf("\nPrice per hour:%d\n", price);
                printf("Enter hour:");
                scanf("%d", &time);
                printf("Numbers of Rooms:");
                scanf("%d", &qty);
                total_amt(price, time, qty);
                payment(upi_id, debit_card, credit_card, password_banking, user_id, payment_type, card, pin, lenght_card, price, time, qty, i, room_n);
            }
        }
        //------------------about hotel------------------
        else if (service == 3)
        {
            printf("\t\t\t\t\t\tAbout Our Hotel\n");
            printf("With a history of over a century and remarkably endearing hospitality, Maidens Hotel offers a journey back in time. Established in 1903 as one of the first hotels of Delhi and recognized as a Heritage Hotel in 1994, Maidens Hotel is a stately survivor of the golden age - a time when steam ruled the waves & the rails, empires flourished and when the rich, the famous and the titled used it as their stage. Its sweeping driveway and the grand façade give an inkling of its star-studded past. Its architecture is the most glorious illustration of old-world European charm with its colonial impressions.A stay at Maidens Hotel is ethereal and unmatched - an experience historically and culturally enriching! Every corner in the hotel has a story to tell, whether it's unraveling the majestic royals of the princely states, the Delhi Durbar with its pre-independence coronation, or the ruling times of The British Raj.Every moment brings you a step closer to nature, with sparkling surroundings of calmness, serenity and tranquility. The pearl-white façade of the building complements the lush jade-like greenery, while peacocks roam\n");
        }

        printf("\nYou want to continue !\n1.Yes\n2.No");
        scanf("%d", &exit);
        if (exit == 2)
        {
            printf("\n\t\t\t\t\t\tSee You Soon :%s\n", name);
            break;
        }
    }

    return 0;
}