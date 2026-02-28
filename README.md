🏥 OOP – Hospital Patient Management System (HPMS)
1️⃣ Assignment Objective

Drawing from the transition from procedural structures to classes, you are required to move beyond simple data containers to build a robust, secure, and scalable real-world application.

This assignment focuses on the Four Pillars of Object-Oriented Programming (OOP) to solve a large-scale software problem that procedural programming cannot handle efficiently.

2️⃣ Problem Statement: The Healthcare & Patient Management System (HPMS)

A modern hospital requires a system to manage thousands of records across various departments including:

Patients

Doctors

Appointments

Billing

You must design an integrated solution that ensures:

✅ Data security through encapsulation

✅ Automatic resource management via constructors and destructors

✅ Dynamic scalability using pointers and heap memory

3️⃣ Technical Requirements & Critical Skills

Your solution must be modular and include the following object-oriented techniques:

3.1 Class Architecture

Define at least six distinct classes. Examples include:

Patient

Doctor

Appointment

MedicalRecord

Bill

Department

3.2 Encapsulation & Data Hiding

All sensitive data (e.g., patient IDs, balance, medical history) must be private.

Implement public getter and setter functions.

Apply strict data validation.

Example:
Ensure that values like bill amounts cannot be negative.

3.3 Automatic Initialization & Cleanup

For every class, implement:

Default Constructor

Parameterized Constructor

Copy Constructor

Destructor

This ensures:

Objects start in a valid state

Automatic cleanup

Prevention of memory leaks

3.4 Dynamic Memory Management

Use:

new

delete

Manage an array of objects dynamically, allowing the hospital system to scale records at runtime.

3.5 Pointer Operations

Use pointers to link objects

Example: A Doctor* pointer inside an Appointment object

Use the arrow operator -> for member access

3.6 Logic Implementation

Your system must include real functionality such as:

💰 Calculating medical bills

🩺 Validating doctor availability

📊 Generating formatted reports using iomanip

4️⃣ Required Functionalities
4.1 Patient Management

Add New Patient

View Patient Details

Update Patient Information

Delete Patient Record

Search Patient (ID, name, etc.)

List All Patients (formatted table)

4.2 Doctor Management

Add New Doctor

View Doctor Details

Update Doctor Information

Delete Doctor Record

Search Doctor (ID, name, specialization)

List All Doctors

Check Doctor Availability

4.3 Appointment Management

Schedule Appointment

View Appointment Details

Reschedule Appointment

Cancel Appointment

List Patient Appointments

List Doctor Appointments

View Daily Schedule

4.4 Medical Records Management

Add Medical Record

View Medical History

Update Medical Record

Search Medical Records (diagnosis/date)

4.5 Billing Management

Generate Bill

View Bill Details

Process Payment

View Payment History

Calculate Total Revenue

List Pending Bills

4.6 Department Management

Add Department

Assign Doctor to Department

View Department Details

List All Departments

4.7 Reporting & Analytics

Patient Summary Report

Doctor Performance Report

Financial Summary Report

Appointment Statistics (daily/weekly/monthly)

4.8 Security & Access Control

User Login System (admin, doctor, receptionist)

Role-Based Access Control

Data Validation

Privacy Protection of sensitive information

5️⃣ Required Modules for Scale

To ensure comprehensive implementation, include:

5.1 Input/Output Handling

Extensive user menus

Formatted data display using iomanip

5.2 Validation Engine

Strict checks for:

IDs

Age

Bill amounts

Dates

Availability

Maintain full data integrity

5.3 Search & Filter Engine

Implement search algorithms

Use pointers and dynamic arrays

Efficient record retrieval

5.4 Security Layer

Access control mechanisms

Role-based restrictions

Secure patient data handling

🎯 Final Goal

Your Healthcare & Patient Management System must:

Demonstrate all Four Pillars of OOP

Encapsulation

Abstraction

Inheritance

Polymorphism

Use dynamic memory

Follow secure coding practices

Implement a real-world scalable architecture
