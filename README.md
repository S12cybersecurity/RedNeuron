# RedNeuron
RedNeuron is a Framework Creator of Malware, this framework it's focused in attacking Windows Machines but are created to execute the creator framework in Linux, you can use it in any Linux distribution you only need the necessary requeriments.

If you want to collaborate with code or ideas you can contact me in s12deff@gmail.com.

If you want to help the development of this tool with money, you can buy one suscription in Medium:
https://medium.com/@s12deff/membership

It's developed in Kali Linux machine, and tested in Kali, Athena OS, Ubuntu and Parrot OS. 

Actually in Version 1.2, the uniques 2 malwares options to create is a Undetectable Reverse Shell to bypass Windows Defender, and Persitence file using Run Register, this tool are developed mainly with 3 languages:
- C++
- Python
- Bash

This tool have a shell to use and move inside RedNeuron, in this moment only have two sections
- Main
- Create

Future Malware tools:
- File Extractor
- C2 Server
- KeyLogger
- Ransomware

![image](https://user-images.githubusercontent.com/79543461/210807455-2dae7b7f-884d-47de-81c3-0f9bde1cbc27.png)

# Installation

**Clone this repository:**

git clone https://github.com/S12cybersecurity/RedNeuron

**Install requeriments:**

apt update && apt install python2 && apt install g++-mingw-w64

**If you don't have Metasploit you need to install.**

Guide: https://adamtheautomator.com/install-metasploit-on-ubuntu/

**Set RedNeuron as executable**

chmod +x RedNeuron

**Python2 requeriments**

wget https://bootstrap.pypa.io/pip/2.7/get-pip.py

python2 get-pip.py

pip2 install pycryptodome

**Compile**

The code it's compiled, but if you want to compile run this command:

gcc redneuron.cpp -lstdc++ -Wwrite-strings -o RedNeuron

# Usage

Execute ./RedNeuron

![image](https://user-images.githubusercontent.com/79543461/210810523-37e7a677-3bfd-45d6-8c0e-a5fc23fd1d6b.png)

If you want to create malware, you execute create command:

![image](https://user-images.githubusercontent.com/79543461/212728043-bdabe8f2-056f-4fcf-ae2d-9cab650b82be.png)

With list command you can see all available malware:

![image](https://user-images.githubusercontent.com/79543461/212728136-0e453634-f5ce-4380-9174-10eb994d4aa8.png)

Create Undetectable Windows Reverse Shell:

![image](https://user-images.githubusercontent.com/79543461/210821342-e18e2053-c7c7-404f-9313-03f2d2a8c32b.png)

Create Windows Persistence File:

![image](https://user-images.githubusercontent.com/79543461/212728269-3ce8ae5e-d3a0-431e-98b0-7cf70ebe4909.png)

