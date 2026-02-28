OOP – Hospital Patient Management System (HPMS)
1. Assignment Objective

Drawing from the transition from procedural structures to classes, you are required to move beyond simple data containers to build a robust, secure, and scalable real-world application.

This assignment focuses on the Four Pillars of OOP to solve a large-scale software problem that procedural programming cannot handle efficiently.

2. Problem Statement: The Healthcare & Patient Management System (HPMS)

A modern hospital requires a system to manage thousands of records across various departments including:

Patients

Doctors

Appointments

Billing

You must design an integrated solution that ensures:

Data security through encapsulation

Automatic resource management via constructors and destructors

Dynamic scalability using pointers and heap memory

3. Technical Requirements & Critical Skills

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

Implement public getter and setter functions with strict data validation.

Example:

Ensure bill amounts cannot be negative.

Ensure patient age is valid.

Ensure contact numbers follow proper format.

3.3 Automatic Initialization & Cleanup

Implement Overloaded Constructors:

Default Constructor

Parameterized Constructor

Copy Constructor

Include Destructors for all classes to:

Handle automatic cleanup

Prevent memory leaks

3.4 Dynamic Memory Management

Use new and delete operators.

Manage arrays of objects dynamically.

Allow the hospital system to scale the number of records at runtime.

3.5 Pointer Operations

Use pointers to link objects.

Example: A Doctor* pointer inside an Appointment object.

Use the arrow operator (->) for member access.

3.6 Logic Implementation

Your system must include behaviors such as:

Calculating medical bills

Validating doctor availability

Generating formatted reports using <iomanip>

4. Required Functionalities
4.1 Patient Management

Add New Patient

Register a new patient with:

Name

Age

ID

Contact

Medical history

View Patient Details

Display complete information of a specific patient.

Update Patient Information

Modify existing patient records.

Delete Patient Record

Remove a patient from the system.

Search Patient

Find patients by:

ID

Name

Other criteria

List All Patients

Display all registered patients in a formatted table.

4.2 Doctor Management

Add New Doctor

Register doctor with:

Specialization

ID

Contact

Availability

View Doctor Details

Update Doctor Information

Delete Doctor Record

Search Doctor

By ID

By name

By specialization

List All Doctors

Check Doctor Availability

4.3 Appointment Management

Schedule Appointment

Link patient and doctor.

View Appointment Details

Reschedule Appointment

Cancel Appointment

List Patient Appointments

List Doctor Appointments

View Daily Schedule

Display all appointments for a given date.

4.4 Medical Records Management

Add Medical Record

Diagnosis

Treatment

Prescription

View Medical History

Update Medical Record

Search Medical Records

By diagnosis

By date

4.5 Billing Management

Generate Bill

Consultation fees

Medicine costs

Tests

View Bill Details

Process Payment

Record payment

Update outstanding balance

View Payment History

Calculate Total Revenue

List Pending Bills

Unpaid

Partially paid

4.6 Department Management

Add Department

Assign Doctor to Department

View Department Details

Display department information

Show associated doctors

List All Departments

4.7 Reporting & Analytics

Patient Summary Report

Formatted report of all patients.

Doctor Performance Report

Number of appointments per doctor.

Financial Summary Report

Revenue

Pending bills

Payment statistics

Appointment Statistics

Daily trends

Weekly trends

Monthly trends

4.8 Security & Access Control

User Login System

Authenticate users:

Admin

Doctor

Receptionist

Role-Based Access

Restrict functionalities based on user role.

Data Validation

Ensure all inputs meet required criteria.

Privacy Protection

Secure access to sensitive patient information.

5. Required Modules for Scale

To ensure comprehensive implementation, include:

5.1 Input/Output Handling

Extensive user menus

Formatted data display using <iomanip>

5.2 Validation Engine

Detailed input checks

Prevent invalid data entry

Maintain data integrity

5.3 Search & Filter Module

Implement search algorithms

Use pointers and dynamic arrays

Efficient filtering of records

5.4 Security Layer

Access control mechanisms

Privacy enforcement

Authentication system

Real-world hospital data protection standards

Summary

This assignment requires building a fully modular, secure, dynamic, and scalable Hospital Patient Management System (HPMS) using:

Encapsulation

Constructors & Destructors

Dynamic memory management

Pointer-based object linking

Role-based access control

Real-world business logic implementation

The system must demonstrate mastery of Object-Oriented Programming principles while solving a realistic large-scale healthcare management problem.
