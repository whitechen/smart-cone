#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import json, requests
import requests
import json as simplejson
import time

#Cone 1
ConeId = requests.get('')	#NOTE: input your request URL
aConeIdM = json.loads(ConeId.text)
aConeId = aConeIdM["result"]

Latitude = requests.get('')	#NOTE: input your request URL
aLatitudeM = json.loads(Latitude.text)
aLatitude = aLatitudeM["result"]

Longitude = requests.get('')	#NOTE: input your request URL
aLongitudeM = json.loads(Longitude.text)
aLongitude = aLongitudeM["result"]

###Change to your database url###
url = "http://111.11.111.111:3000/beacon"
data = {'id': aConeId, 'lat': aLatitude, 'lng': aLongitude}
headers = {'Content-type': 'application/json'}
r = requests.post(url, data=json.dumps(data), headers=headers)

#Cone 2
ConeId = requests.get('')	#NOTE: input your request URL
aConeIdM = json.loads(ConeId.text)
aConeId = aConeIdM["result"]

Latitude = requests.get('')	#NOTE: input your request URL
aLatitudeM = json.loads(Latitude.text)
aLatitude = aLatitudeM["result"]

Longitude = requests.get('')	#NOTE: input your request URL
aLongitudeM = json.loads(Longitude.text)
aLongitude = aLongitudeM["result"]

###Change to your database url###
url = "http://111.11.111.111:3000/beacon"
data = {'id': aConeId, 'lat': aLatitude, 'lng': aLongitude}
headers = {'Content-type': 'application/json'}
r = requests.post(url, data=json.dumps(data), headers=headers)

