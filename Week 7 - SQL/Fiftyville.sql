-- Keep a log of any SQL queries you execute as you solve the mystery.

--1st The crime scene report  
SELECT id, description FROM crime_scene_reports
    WHERE street = "Humphrey Street" AND day = 28 AND month = 07 AND year = 2021;

--2nd Pull the reports
SELECT name, transcript FROM interviews
    WHERE day = 28 AND month = 07 AND year = 2021;

--3rd get license info
SELECT name, phone_number, passport_number, license_plate FROM people
    WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
        WHERE day = 28 AND month = 07 AND year = 2021 AND hour = 10 AND minute >=15 AND minute <=25
        AND activity = "exit");

--4th bank accounts details
SELECT name, passport_number, bank_accounts.account_number FROM people, atm_transactions, bank_accounts
    WHERE people.id = bank_accounts.person_id
    AND atm_transactions.account_number = bank_accounts.account_number
    AND day = 28 AND month = 07 AND year = 2021
    AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

--5th phone records for call and recieve
SELECT caller, name FROM phone_calls, people
    WHERE people.phone_number = caller
    AND day = 28 AND month = 07 AND year = 2021 AND duration < 60
    ORDER BY phone_calls.id;
SELECT receiver, name FROM phone_calls, people
    WHERE people.phone_number = receiver
    AND day = 28 AND month = 07 AND year = 2021 AND duration < 60
    ORDER BY phone_calls.id;

--6th check the flight departures for the next day
SELECT airports.city, airports.full_name, people.name, people.passport_number FROM airports, flights, passengers, people
    WHERE airports.id = flights.destination_airport_id
    AND flights.id = passengers.flight_id AND passengers.passport_number = people.passport_number
    AND flights.origin_airport_id = (SELECT airports.id FROM airports WHERE city = "Fiftyville")
    AND day = 29 AND month = 07 AND year = 2021 ORDER BY flights.hour;

-------------------------------------

SELECT TrackId, AlbumId, Composer, UnitPrice FROM tracks

SELECT CustomerId, InvoiceDate, Total FROM invoices WHERE Total > 20

SELECT DISTINCT name FROM playlist ORDER BY playlist_id

SELECT * FROM album WHERE LENGTH(title) < 4

SELECT customer_id, SUBSTR(country, 3) AS new_country FROM customer ORDER BY country


SELECT COUNT(DISTINCT customer_id) FROM invoice


SELECT * FROM customer WHERE LENGTH(city) > 9;


SELECT employee_id, SUBSTR(last_name, 1, 3) AS new_last_name
FROM employee ORDER BY postal_code


SELECT column_name
FROM table_name AS alias_name

CREATE TABLE AfricaSales AS
(
SELECT * FROM GlobalSales WHERE Region = "Africa"
)

---------------------------------------------

--The THIEF is: Bruce
--The city the thief ESCAPED TO: New York City
--The ACCOMPLICE is: Robin
44
