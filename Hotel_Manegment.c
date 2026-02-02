#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void total_amt(int price, int time, int qty)
{
    printf("Total Amt.:%d\n", price * time * qty);
}
void room(int qty, int room_n)
{
    srand((0));
    printf("How many Room you want to book :");
    scanf("%d", &room_n);
    for (qty = 1; qty <= room_n; qty++)
    {
        int random_num = rand() % 510;
        printf("Room No. : %d\n", random_num);
    }
}
// void room(int qty)
// {
//     srand((0));
//     if (qty == 1)
//     {
//         do
//         {
//             int random_num = rand() % 500;
//             printf("Room No. : %d\n", random_num);
//             qty++;

//         } while (qty <= 2);
//     }

//     if (qty == 2)
//     {
//         do
//         {
//             int random_num = rand() % 510;
//             printf("Room No. : %d\n", random_num);
//             qty++;

//         } while (qty <= 3);
//     }

//     if (qty == 3)
//     {
//         do
//         {
//             int random_num = rand() % 510;
//             printf("Room No. : %d\n", random_num);
//             qty++;

//         } while (qty <= 5);
//     }

//     if (qty == 4)
//     {
//         do
//         {
//             int random_num = rand() % 510;
//             printf("Room No. : %d\n", random_num);
//             qty++;

//         } while (qty <= 7);
//     }

//     if (qty == 5)
//     {
//         do
//         {
//             int random_num = rand() % 510;
//             printf("Room No. : %d\n", random_num);
//             qty++;

//         } while (qty <= 9);
//     }
//}

int main()
{
    char name[25], email_save[100], country[40];
    char state[36][40] = {"Andhra Pradesh", "Arunachal Pradesh", "Assam", "Bihar", "Chhattisgarh", "Goa", "Gujarat", "haryana", "Himachal Pradesh", "Jharkhand", "Karnataka", "Kerala", "Madhya Pradesh", "Maharashtra", "Manipur", "Meghalaya", "Mizoram", "Nagaland", "Odisha", "Punjab", "Rajasthan", "Sikkim", "Tamil Nadu", "Telangana", "Tripura", "Uttar Pradesh", "Uttarakhand", "West Bengal", "Andaman and Nicobar Islands", "Chandigarh", "Dadra and Nagar Haveli", "Daman and Diu", "Jammu Kashmir", "Lakshadweep", "Delhi National Capital Territory", "Puducherry"};
    char save_password[100], enter_password[100], email_enter[100];
    int service, enquiry;
    int lenght = 10;
    int phone, gender, book_room, price, time;
    int qty, room_n, random_num;
    //----------------------Home Page------------------------

    // printf("%s\n",list[0]);

    printf("\n\t\t\t\t\t\tHOTEL\n");
    printf("Enter your Name :");
    scanf("%s", &name);
    printf("\t\t\t\t\t\tWelcome %s\n", name);
    printf("Select Services \n1.Enquiry\n2.Room Booking\n3.About our Hotel\n");
    printf("Select :");
    scanf("%d", &service);

    if (service == 1)
    {
        printf("\t\t\t\t\t\tEnquiry\n");
        printf("About which Room you want know\n1.Heritage Rooms\n2.Premier Rooms\n3.Deluxe Suite with living room\n4.Luxury Suite with living room\n5.Lutyens Suite\nSelect Option :");
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
    //--------------------------------------room booking-------------------------------------------------

    else if (service == 2)
    {
        printf("\t\t\t\t\t\t\nBOOKING ROOM\n");
        printf("\nName*:%s\n", name);

        while (1)
        {
            printf("Phone*:");
            scanf("%d", &phone);
            lenght == phone;

            if (lenght == 10)
            {
                printf("Valid Number\n ");
                break;
            }
            else
            {
                printf("Invalid number try again!\n");
            }
        }

        printf("\nGender* \n1.Male\t2.Female\t3.Other");
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
            printf("\nEmail :");
            scanf("%s", &email_save);

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

        printf("\nCountry:");
        scanf("%s", &country);
        int i;
        for (i = 0; i < 36; i++)
        {
            printf("%s\n", state[i]);
        }

        printf("\nEnter State:");
        scanf("%d", &i);
        printf("%s\n", state[i]);

        printf("Enter Password :");
        scanf("%s", &save_password);

        printf("\n\t\t\t\t\t\tSucessful registration");

        //----------------------------- Login page ---------------------------------------
        while (1)
        {
            printf("\nEnter Email :");
            scanf("%s", &email_enter);

            printf("Password :");
            scanf("%s", &enter_password);
            
        }

        printf("\nSelect Room that you want to book\n1\n.Heritage Rooms\n2.Premier Rooms\n3.Deluxe Suite with living room\n4.Luxury Suite with living room\n5.Lutyens Suite\nEnter Room :");
        scanf("%d", &book_room);

        if (book_room == 1)
        {
            printf("Heritage Room\n");

            price = 200;
            printf("Price per hour:%d\n", price);
            printf("Enter hour:", time);
            scanf("%d", &time);
            printf("How many Room you want to book :");
            scanf("%d", &qty);
            total_amt(price, time, qty);
            room(qty, room_n);
        }

        if (book_room == 2)
        {
            printf("Premir Room\n");

            price = 300;
            printf("Price per hour:%d\n", price);
            printf("Enter hour:", time);
            scanf("%d", &time);
            printf("How many Room you want to book :");
            scanf("%d", &qty);

            total_amt(price, time, qty);
            room(qty, room_n);
        }

        if (book_room == 3)
        {
            printf("Deluxe Suite with living room\n");

            price = 400;
            printf("Price per hour:%d\n", price);
            printf("Enter hour:", time);
            scanf("%d", &time);
            printf("How many Room you want to book :");
            scanf("%d", &qty);

            total_amt(price, time, qty);
            room(qty, room_n);
        }

        if (book_room == 4)
        {
            printf("Luxury Suite with living room\n");

            price = 500;
            printf("Price per hour:%d\n", price);
            printf("Enter hour:", time);
            scanf("%d", &time);
            printf("How many Room you want to book :");
            scanf("%d", &qty);
            total_amt(price, time, qty);
            room(qty, room_n);
        }

        if (book_room == 5)
        {
            printf("Lutyens Suite\nEnter Room\n");

            price = 600;
            printf("Price per hour:%d\n", price);
            printf("Enter hour:", time);
            scanf("%d", &time);
            printf("How many Room you want to book :");
            scanf("%d", &qty);
            total_amt(price, time, qty);
            room(qty, room_n);
        }
    }

    else if (service == 3)
    {
        printf("\t\t\t\t\t\tAbout Our Hotel\n");
        printf("With a history of over a century and remarkably endearing hospitality, Maidens Hotel offers a journey back in time. Established in 1903 as one of the first hotels of Delhi and recognized as a Heritage Hotel in 1994, Maidens Hotel is a stately survivor of the golden age - a time when steam ruled the waves & the rails, empires flourished and when the rich, the famous and the titled used it as their stage. Its sweeping driveway and the grand façade give an inkling of its star-studded past. Its architecture is the most glorious illustration of old-world European charm with its colonial impressions.A stay at Maidens Hotel is ethereal and unmatched - an experience historically and culturally enriching! Every corner in the hotel has a story to tell, whether it's unraveling the majestic royals of the princely states, the Delhi Durbar with its pre-independence coronation, or the ruling times of The British Raj.Every moment brings you a step closer to nature, with sparkling surroundings of calmness, serenity and tranquility. The pearl-white façade of the building complements the lush jade-like greenery, while peacocks roam\n");
    }

    printf("\n\t\t\t\t\t\tSee You Soon :%s\n", name);

    printf("");

    return 0;
}
