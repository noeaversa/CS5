-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports WHERE street = "Chamberlin Street" AND day = 28;
--id  | year | month | day | street            | description
--295 | 2020 | 7     | 28  | Chamberlin Street | 

SELECT * FROM interviews WHERE day = 28 AND month = 7;


SELECT * FROM courthouse_security_logs  WHERE year = 2020 AND day = 28 AND month = 7;

SELECT * FROM people WHERE name = "Eugene"; --280744 | Eugene | (666) 555-5774 | 9584465633 | 47592FJ
SELECT * FROM courthouse_security_logs WHERE license_plate = "47592FJ";
SELECT * FROM atm_transactions WHERE atm_location = "Fifer Street" AND year = 2020 AND day = 28 AND month = 7;


SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id WHERE account_number = 28500762;
SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id WHERE account_number = 28296815;
SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id WHERE account_number = 76054385;
--76054385 | 449774 | 2015 | 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id WHERE account_number = 49610011;
--49610011 | 686048 | 2010 | 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id WHERE account_number = 16153065;
SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id WHERE account_number = 86363979;
SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id WHERE account_number = 25506511;
SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id WHERE account_number = 81061156;
SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id WHERE account_number = 26013199;
--26013199 | 514354 | 2012 | 514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE


SELECT * FROM phone_calls WHERE year = 2020 AND day = 28 AND month = 7 AND duration <= 60;

--suspects:
--Ernest called Berthold
--Madison called James
--Russel called Philip

SELECT * FROM people WHERE phone_number = "(367) 555-5533"; 
SELECT * FROM people WHERE phone_number = "(770) 555-1861"; 
SELECT * FROM people WHERE phone_number = "(286) 555-6063"; 

SELECT * FROM airports WHERE city = "Fiftyville";
SELECT * FROM flights JOIN airports ON flights.origin_airport_id = airports.id WHERE year = 2020 AND day = 29 AND month = 7 AND origin_airport_id = 8;

SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id WHERE passport_number = "5773159633"; --Ernest
SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id WHERE passport_number = "1988161715"; -- Madison
SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id WHERE passport_number = "3592750733"; -- Russel


SELECT * FROM people WHERE name = "Berthold"; -- DOESNT HAVE PASSPORT
SELECT * FROM people WHERE name = "James"; -- passport: 2438825627

SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id WHERE passport_number = "?"; --Berthold
SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id WHERE passport_number = "2438825627";
SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id WHERE passport_number = "3391710505";

SELECT * FROM flights JOIN airports ON destination_airport_id = airports.id WHERE destination_airport_id = 4;
