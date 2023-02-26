i=1

while [ $i -ne 0 ]
do
	echo "Press enter to continue..."

	read dummy

	clear

	echo "1 - Ieșire"
	echo "2 - Afișare: ID-ul procesului initiat la executarea scriptului, tipul sistemului de operare, numarul de secunde de cand s-a executat scriptul și calea curentă"
	echo "3 - Afișarea numarului săptămânii din an, si a zilei săptămânii în care va fi Crăciunul în acest an"
	echo "4 - Afișarea primelor 2 shell-urilor instalate în sistem"
	echo "5 - Afișarea pentru toți utilizatorii din sistem a numelui de login, a user ID-ului, a numelui complet si a directorului de home"
	echo "6 - Afişare ultimele linii începând cu linia 9 din fișierul /etc/protocols folosind comanda tail"
	echo "7 - Afișare tip procesor şi mărimea cache-ului"
	echo "8 - Scrieți comanda ls care afișează toate numele de directoare din directorul /proc care nu reprezintă imaginea unui proces pe disc"
	echo "9 - Sa se afiseze toate fisierele de log. Sa se creeze o funcție care primește ca si parametrii cititi de la tastatura un nume de fișier de log (ori curent ori arhivat) și un text, si care va căuta si afișa liniile care conțin textul primit ca si parametru"
	
	read i

	case $i in
		1) break;;
		2) echo "ID: " $$ '\n' 
		  lsb_release -d 
		 date -ud "@$SECONDS" "+Time elapsed: %H:%M:%S"
		 pwd ;;
		3) echo "Saptamana si ziua in care pica Craciunul:"
		date -d 25-Dec +%U
		date -d 25-Dec +%A;;
		4) cat /etc/shells | head -3;;
		5) awk -F: '{print $1"  "$3"  "$5 "  "$6}' /etc/passwd;;
		6)tail -n 9 /etc/protocols;;
		7)cat /etc/protocols;;
		8)ls /proc | grep [a-zA-Z];;
		9) cd /var/log
		ls
		echo -e "\nChoose a log file: "
		read choice
		echo "Search: "
		read search
		if [[ "$choice" == *.gz ]]
		then sudo zgrep "${search}" $choice
		else sudo grep "${search}" $choice
		fi ;;
		*) echo "Wrong";;
	esac
done


