#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// QR Code and Payment functions
void generate_qr_code(int amount, char* payment_id, char* upi_id) {
    FILE *html_file = fopen("qr_payment.html", "w");
    if (html_file == NULL) {
        printf("Error creating payment page!\n");
        return;
    }

    fprintf(html_file, "<!DOCTYPE html>\n");
    fprintf(html_file, "<html lang='en'>\n");
    fprintf(html_file, "<head>\n");
    fprintf(html_file, "    <meta charset='UTF-8'>\n");
    fprintf(html_file, "    <meta name='viewport' content='width=device-width, initial-scale=1.0'>\n");
    fprintf(html_file, "    <title>Hotel Payment - QR Code</title>\n");
    fprintf(html_file, "    <script src='https://cdnjs.cloudflare.com/ajax/libs/qrcodejs/1.0.0/qrcode.min.js'></script>\n");
    fprintf(html_file, "    <style>\n");
    fprintf(html_file, "        * { margin: 0; padding: 0; box-sizing: border-box; }\n");
    fprintf(html_file, "        body { font-family: 'Arial', sans-serif; background: linear-gradient(135deg, #667eea 0%%, #764ba2 100%%); min-height: 100vh; display: flex; justify-content: center; align-items: center; padding: 20px; }\n");
    fprintf(html_file, "        .container { background: white; border-radius: 15px; box-shadow: 0 10px 40px rgba(0,0,0,0.2); padding: 40px; max-width: 500px; width: 100%%; }\n");
    fprintf(html_file, "        .header { text-align: center; margin-bottom: 30px; }\n");
    fprintf(html_file, "        .header h1 { color: #333; font-size: 28px; margin-bottom: 10px; }\n");
    fprintf(html_file, "        .hotel-name { color: #667eea; font-size: 14px; font-weight: bold; }\n");
    fprintf(html_file, "        .payment-details { background: #f8f9fa; padding: 20px; border-radius: 10px; margin-bottom: 25px; border-left: 4px solid #667eea; }\n");
    fprintf(html_file, "        .detail-row { display: flex; justify-content: space-between; margin-bottom: 10px; font-size: 14px; }\n");
    fprintf(html_file, "        .detail-label { color: #666; font-weight: bold; }\n");
    fprintf(html_file, "        .detail-value { color: #333; }\n");
    fprintf(html_file, "        .amount { font-size: 18px; color: #28a745; font-weight: bold; }\n");
    fprintf(html_file, "        .qr-section { text-align: center; margin: 30px 0; }\n");
    fprintf(html_file, "        .qr-section h3 { color: #333; margin-bottom: 20px; font-size: 16px; }\n");
    fprintf(html_file, "        #qrcode { display: inline-block; padding: 15px; background: white; border: 2px solid #667eea; border-radius: 10px; }\n");
    fprintf(html_file, "        .instructions { background: #fff3cd; padding: 15px; border-radius: 10px; margin: 20px 0; border-left: 4px solid #ffc107; }\n");
    fprintf(html_file, "        .instructions h4 { color: #856404; margin-bottom: 10px; font-size: 14px; }\n");
    fprintf(html_file, "        .instructions ol { margin-left: 20px; color: #856404; font-size: 13px; line-height: 1.6; }\n");
    fprintf(html_file, "        .footer { text-align: center; margin-top: 30px; padding-top: 20px; border-top: 1px solid #ddd; color: #666; font-size: 12px; }\n");
    fprintf(html_file, "        .status { margin-top: 20px; padding: 10px; border-radius: 5px; text-align: center; font-weight: bold; }\n");
    fprintf(html_file, "    </style>\n");
    fprintf(html_file, "</head>\n");
    fprintf(html_file, "<body>\n");
    fprintf(html_file, "    <div class='container'>\n");
    fprintf(html_file, "        <div class='header'>\n");
    fprintf(html_file, "            <div class='hotel-name'>LUXURY HOTEL MANAGEMENT</div>\n");
    fprintf(html_file, "            <h1>QR Code Payment</h1>\n");
    fprintf(html_file, "        </div>\n");
    fprintf(html_file, "\n");
    fprintf(html_file, "        <div class='payment-details'>\n");
    fprintf(html_file, "            <div class='detail-row'>\n");
    fprintf(html_file, "                <span class='detail-label'>Payment ID:</span>\n");
    fprintf(html_file, "                <span class='detail-value'>%s</span>\n", payment_id);
    fprintf(html_file, "            </div>\n");
    fprintf(html_file, "            <div class='detail-row'>\n");
    fprintf(html_file, "                <span class='detail-label'>UPI ID:</span>\n");
    fprintf(html_file, "                <span class='detail-value'>%s</span>\n", upi_id);
    fprintf(html_file, "            </div>\n");
    fprintf(html_file, "            <div class='detail-row'>\n");
    fprintf(html_file, "                <span class='detail-label'>Amount:</span>\n");
    fprintf(html_file, "                <span class='detail-value amount'>₹%d</span>\n", amount);
    fprintf(html_file, "            </div>\n");
    fprintf(html_file, "        </div>\n");
    fprintf(html_file, "\n");
    fprintf(html_file, "        <div class='qr-section'>\n");
    fprintf(html_file, "            <h3>Scan QR Code to Pay</h3>\n");
    fprintf(html_file, "            <div id='qrcode'></div>\n");
    fprintf(html_file, "        </div>\n");
    fprintf(html_file, "\n");
    fprintf(html_file, "        <div class='instructions'>\n");
    fprintf(html_file, "            <h4>How to Pay:</h4>\n");
    fprintf(html_file, "            <ol>\n");
    fprintf(html_file, "                <li>Open your UPI App (Google Pay, PhonePe, Paytm)</li>\n");
    fprintf(html_file, "                <li>Tap on 'Send Money' or 'Scan QR Code'</li>\n");
    fprintf(html_file, "                <li>Scan the QR code above</li>\n");
    fprintf(html_file, "                <li>Verify amount and complete payment</li>\n");
    fprintf(html_file, "                <li>Enter your UPI PIN</li>\n");
    fprintf(html_file, "            </ol>\n");
    fprintf(html_file, "        </div>\n");
    fprintf(html_file, "\n");
    fprintf(html_file, "        <div class='footer'>\n");
    fprintf(html_file, "            <p>Payment valid for 15 minutes</p>\n");
    fprintf(html_file, "            <p>Support: support@luxuryhotel.com</p>\n");
    fprintf(html_file, "        </div>\n");
    fprintf(html_file, "    </div>\n");
    fprintf(html_file, "\n");
    fprintf(html_file, "    <script>\n");
    fprintf(html_file, "        var qrData = 'upi://pay?pa=%s&pn=HotelPayment&am=%d&tn=Hotel%%20Booking&tr=%s';\n", upi_id, amount, payment_id);
    fprintf(html_file, "        new QRCode(document.getElementById('qrcode'), {\n");
    fprintf(html_file, "            text: qrData,\n");
    fprintf(html_file, "            width: 250,\n");
    fprintf(html_file, "            height: 250,\n");
    fprintf(html_file, "            colorDark: '#667eea',\n");
    fprintf(html_file, "            colorLight: '#ffffff',\n");
    fprintf(html_file, "            correctLevel: QRCode.CorrectLevel.H\n");
    fprintf(html_file, "        });\n");
    fprintf(html_file, "    </script>\n");
    fprintf(html_file, "</body>\n");
    fprintf(html_file, "</html>\n");

    fclose(html_file);
}
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

void payment(char upi_id[50], char debit_card[20], char credit_card[20], char password_banking[50], char user_id[50], int payment_type, int card, int pin, int lenght_card, int price, int hours, int qty, int i, int room_n)
{
    lenght_card = 0;
    char payment_id[50];
    int total_amount;

    while (1)
    {

        printf("\n========== PAYMENT METHOD ==========\n");
        printf("1. UPI Payment\n");
        printf("2. Card Payment\n");
        printf("3. Banking Channel\n");
        printf("4. QR Code Payment (Recommended)\n");
        printf("5. Cash/Offline\n");
        printf("====================================\n");
        printf("Select Payment Method >");
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
                    total_amt(price, hours, qty);
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
                        total_amt(price, hours, qty);
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
                        total_amt(price, hours, qty);
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
            total_amt(price, hours, qty);
            printf("Enter Pin No.:");
            scanf("%d", &pin);
            printf("\nSecessfull Payment\n");
            room(qty, room_n);
        }

        if (payment_type == 4)
        {
            printf("\n\t\t\t\t\t\t=== QR CODE PAYMENT ===\n");
            printf("This is the fastest and most secure way to pay!\n\n");
            
            // Generate unique payment ID
            sprintf(payment_id, "HOTEL%d%d", (rand() % 10000) + (rand() % 1000), rand() % 999);
            
            // Calculate total amount
            total_amount = price * hours * qty;
            
            // Get UPI ID
            printf("Enter Your UPI ID (e.g., yourname@paytm): ");
            scanf("%s", upi_id);
            
            // Validate UPI ID
            if (strstr(upi_id, "@") == NULL) {
                printf("Invalid UPI ID format!\n");
                break;
            }
            
            printf("\n=== PAYMENT SUMMARY ===\n");
            printf("Payment ID: %s\n", payment_id);
            printf("Amount: Rs. %d\n", total_amount);
            printf("UPI ID: %s\n", upi_id);
            printf("Status: Opening Payment Page...\n\n");
            
            // Generate QR code HTML page
            generate_qr_code(total_amount, payment_id, upi_id);
            
            // Automatically open the payment page in default browser
            system("start qr_payment.html");
            
            printf("Payment page opened in your browser automatically!\n");
            printf("Scan the QR code with your UPI app to complete payment.\n\n");
            
            printf("Enter PIN to confirm payment (or 0 to cancel): ");
            scanf("%d", &pin);
            
            if (pin != 0) {
                printf("\n✓ Payment Successful!\n");
                printf("✓ Transaction ID: %s\n", payment_id);
                room(qty, room_n);
            } else {
                printf("\nPayment cancelled.\n");
            }
        }

        if (payment_type == 5)
        {
            printf("Cash/Offline Payment\n");
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