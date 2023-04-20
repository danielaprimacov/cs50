-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2021
AND street = "Humphrey Street";

SELECT * FROM interviews WHERE year = 2021 AND day = 28 AND month = 7 AND transcript LIKE "%thief%";

SELECT * FROM bakery_security_logs WHERE year = 2021 AND day = 28 AND month = 7 AND hour < 10;

SELECT * FROM atm_transactions WHERE year = 2021 AND day = 28 AND month = 7 AND transaction_type = "withdraw"
AND atm_location = "Leggett Street";