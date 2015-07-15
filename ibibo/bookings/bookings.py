'''
Simulating and testing SQL queries using python script
@Author: Rohith
'''

import math
import sqlite3
import time
from datetime import date, datetime

def create_booking_db():
	'''
	Creating tables using sqlite3
	'''
	conn = sqlite3.connect('test.db')
	print "opened database successfully"
	conn.execute(''' create table user_details (
                                uid INT not null,
				Name char(50) not null,
				Email char(50) not null,
				Mobile char(50) not null,
				Constraint uid PRIMARY KEY (Name, Email, Mobile)); ''')
	conn.execute(''' create table bookings (
				uid INT not null,
				BookingDate date not null,
				Bookingid char(50) not null,
				AmountPaid int not null); ''')
	conn.close()
	print "Database closed succesfully"
				    

def insert_data_into_booking_db():
	'''
	Inserting some random valuesa and creating two tables for db Normalization
	'''
	conn = sqlite3.connect('test.db')
	print "Opened database successfully"
	conn.execute(''' insert into user_details (uid, Name, Email, Mobile) values
			                      (1, 'Rohith','rohith.uppala369@gmail.com','9591951940'); ''')
	conn.execute(''' insert into bookings (uid, BookingDate, Bookingid, AmountPaid) values 
					      (1, '2014-6-12', '123',  500); ''')
	conn.execute(''' insert into bookings (uid, BookingDate, Bookingid, AmountPaid) values 
					      (1, '2013-6-22', '234',  1500); ''')
	conn.execute(''' insert into bookings (uid, BookingDate, Bookingid, AmountPaid) values 
					      (1, '2012-7-12', '345',  2500); ''')
	
	conn.execute(''' insert into user_details (uid, Name, Email, Mobile) values 
						(2, 'Ravi','ravi@gmail.com','9591951941'); ''')
	conn.execute(''' insert into bookings (uid, BookingDate, Bookingid, AmountPaid) values
                                              (2, '2014-27-12', '786', 1500); ''')
	conn.execute(''' insert into bookings (uid, BookingDate, Bookingid, AmountPaid) values
                                              (2, '2013-12-12', '987', 4500); ''')


	conn.execute(''' insert into user_details (uid, Name, Email, Mobile) values
						(3,'Raju','raju@gmail.com','9591951942'); ''')
	conn.execute(''' insert into bookings (uid, BookingDate, Bookingid, AmountPaid) values
                                              (3, '2014-12-8', '345', 2500); ''')
		

	conn.execute(''' insert into user_details (uid, Name, Email, Mobile) values
					      (4, 'Ramu','ramu@gmail.com','9591951943'); ''')
	conn.execute(''' insert into bookings (uid, BookingDate, Bookingid, AmountPaid) values
                                              (4, '2013-26-9', '456', 3500); ''')
	conn.commit()
	conn.close()
	print "Database Closed Succesfully"


def run_sql_queries():
	'''
	Executing queries on database
	'''
	conn = sqlite3.connect('test.db')
	print "How much days old: "
	days = int(raw_input())

	# First Query
	sql_query = "select Name, Email, Mobile from  user_details where Name not in (select distinct(u.Name) from user_details u, bookings b where (u.uid = b.uid and  b.BookingDate  >= date('now', '-%d day')));" %(days)

	cursor  = conn.execute(sql_query)
	results = []

	for row in cursor:
		results.append(row[0])

	if(len(results) == 0):
		print "No users who have not done booking since last %d days" %(days)
	else:
		print "\nUsers who did not do any booking since last %d days: " %(days)
		for row in results: print row

	# Second Query
	sql_query = "select b.Bookingid, u.Name, MAX(b.Bookingdate) from  user_details u, bookings b where u.uid = b.uid and u.Name not in (select distinct(u.Name) from user_details u, bookings b where (u.uid = b.uid and  b.BookingDate  >= date('now', '-%d day'))) group by u.Name;" %(days)
	cursor = conn.execute(sql_query)
	results = []
	for row in cursor: 
		results.append(row[0])
	
	if len(results) == 0:
		print "No users who have not done booking since last %d days" %(days)
	else:
		print "Last booking id's of those users are: "
		for row in results:
			print row
	conn.close()


# Driver Function
if __name__ == "__main__":
#	create_booking_db()
#	insert_data_into_booking_db()
	run_sql_queries()
