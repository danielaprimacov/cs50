import cs50
import csv

students = []
houses = []
relations = []


# Create houses table
def create_houses(house, houses, head):
    count = 0
    for i in houses:
        if i["house"] == house:
            count += 1
    if count == 0:
        houses.append({"house": house, "head": head})

# Create students table
def create_student(name, students):
    students.append({"student_name": name})

# Create relationships
def create_relation(name, house, relations):
    relations.append({"student_name": name, "house": house})


# Open students file
with open("students.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        name = row["student_name"]
        house = row["house"]
        head = row["head"]

        create_houses(house, houses, head)
        create_student(name, students)
        create_relation(name, house, relations)

# Open database
db = cs50.SQL("sqlite:///roster.db")
# Insert values into tables
for student in students:
    db.execute("INSERT INTO new_students (student_name) VALUES (?)", student["student_name"])

for relation in relations:
    db.execute("INSERT INTO relationship (student_name, house) VALUES (?, ?)", relation["student_name"], relation["house"])

for house in houses:
    db.execute("INSERT INTO new_houses (house, head) VALUES (?, ?)", house["house"], house["head"])