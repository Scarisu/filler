
## 42Filler-game is a Script to help corrector execute and correct The
## filler project in 42school

## made by abdeljalil NACEUR UID:abnaceur
## E-mail: contact@naceur-abdeljalil.com

## Feel free to distribute and/or modify this script



## Information

echo "\033[43;30m============42Filler.game==========\033[0m"
echo "\033[0mUsage:======================================================"
echo "||	sh RUN_42Filler-game.sh								"
echo "||	1. The VM resources should be in the same source path.	"
echo "||	2. RUN_42Filler-game.sh should be in the same source path.	"
echo "||	3. Make sure the file auteur exist.						"
echo "==============================================================="

echo "\033[40;7mPRESS ENTER TO CONTINUE...\033[0m"
read var_break
if [ $var_break ]
then
	echo " "
fi

## get the player name from the author file 
yourname=$(cat auteur)


## Define the opponent 
echo "\033[32mChoose an opponent:\033[0m"
echo "		1. champely"
echo "		2. abanlin"
echo "		3. grati"
echo "		4. carli"
echo "		5. hcao"
echo "		6. superjeannot\n"

echo "\033[42;30mEnter the apponent number:\033[0m"
read opnt

if [ $opnt == "1" ]
then
	opnt="champely"
fi

if [ $opnt == "2" ]
then
	opnt="abanlin"
fi

if [ $opnt == "3" ]
then
	opnt="grati"
fi
if [ $opnt == "4" ]
then
	opnt="carli"
fi
if [ $opnt == "5" ]
then
	opnt="hcao"
fi
if [ $opnt == "6" ]
then
	opnt="superjeannot"
fi
echo "\n"

## Define the player role
echo "\033[42;30mPlayer roles:\033[0m"
echo "		1. First player"
echo "		2. Second player\n"

echo "\033[42;30mRole number:\033[0m"
read position

if [ $position == "1" ]
then 
	{
		pl1=$yourname
		pl2=$opnt
	}
else
	{
		pl1=$opnt
		pl2=$yourname
	}
fi 

echo "\n"

## Define the map arena of the battle
echo "\033[42;30mChoose map: (ex: 00 or 02):\033[0m"
echo "1. map00"
echo "2. map01"
echo "3. map02"

echo "\033[42;30mMap number:\033[0m"
read mapnum

if [ $mapnum == "1" ]
then
	mapnum=00
fi


if [ $mapnum == "2" ]
then
	mapnum=01
fi

if [ $mapnum == "3" ]
then
	mapnum=02
fi

echo "\033[40;7mPRESS ENTER TO CONTINUE...\033[0m"
read var_break
if [ $var_break]
then
	echo " "
fi

## Compile the library
make re

 ## The descriptive header
echo "\033[44;33;1m|************************************************"
echo "|-> STATUS:		START	  "
echo "|-> PLAYER:		$pl1 vs $pl2	  "
echo "|-> MAP:		$mapnum	  "
echo "|-> ROUNDS:		05        "
echo "=====================================================\n"

echo "				=================="
echo "========================|   $pl1 VS $pl2  |========================"
echo "========================|   FIGHT BEGIN  |========================"
echo "			==================								\033[0m\n"

## PROGRESS BAR

echo "THIS MAY TAKE A WHILE, PLEASE BE PATIENT WHILE ______ IS RUNNING..."

## depending on the position define the player path
if [ $position == "1" ]
then 
	{
		path_player1=./
		path_player2=../resources/players/
	}
else
	{
		path_player1=../resources/players/
		path_player2=./
	}
fi

## Start the game 05 rounds 
for i in `seq 1 5`;
		do
		../resources/filler_vm -p1 $path_player1$pl1.filler -p2 $path_player2$pl2.filler -f ../resources/maps/map$mapnum > FIGHT_$i

## get the score from the output file
		cat FIGHT_$i | tail -n 2 | cut -d : -f2 | cut -d " " -f2 > score
		pl1_o=$(cat score | head -1)
		pl2_x=$(cat score | tail -n 1)

## Convert it to integer
		let pl1_o=pl1_o+0
		let pl2_x=pl2_x+0

## Caculate score for each player
		if [ $pl1_o -ge $pl2_x ]
		then
			o+=1
		else
			x+=1
		fi

## A simple progress bar
		printf  "▓▓▓▓"
		sleep 1
done
		printf '] done!'
		sleep 0.42
		echo "\n"

## Get the score for o and x
echo $o | wc -c | tr -d " " > o
echo $x | wc -c | tr -d " " > x

## Convert it to integer
	o=$(cat o)
	o="$(($o-1))"

	x=$(cat x)
	x="$(($x-1))"

echo "\033[42;30mShow fight's result: yes/no\033[0m"
read show

if [ $show == "yes" ]
then
	{
		for i in `seq 1 5` 
		do
	echo "\033[42;30mFIGHT_$i[round$i][FINISHED]\033[0m"
	cat FIGHT_$i | tail -n 2 | cut -d : -f2 | cut -d " " -f2 > score
	pl1_o=$(cat score | head -1)
	pl2_x=$(cat score | tail -n 1)

	echo "\033[44;7m|--SCORE:--------\033[0m"
	echo "\033[44;7m|\033[0m $pl1: $pl1_o \033[44;7m|\033[0m"
	echo "\033[44;7m|\033[0m $pl2: $pl2_x \033[44;7m|\033[0m"
	echo "\033[44;7m|---------------\033[0m\n"
	done
	}
fi

echo "\033[44;33m			=================="
echo "=========================|   FIGHT ENDS  |=========================="
echo "			=================\033[0m\n"

echo "\033[41;7m|----|| RESULTS ||-----------------\033[0m"
echo "\033[41;7m|$pl1's score : $o wins\033[0m"
echo "\033[41;7m|$pl2's score : $x wins\033[0m"
echo "\033[41;7m|-----------------------------------\033[0m\n" 

if [ $o -gt $x ]
then
	{
echo "\033[44;33m			  ************=======********************"
echo "			*************||WINNER||********************"
echo "			***********@@ $pl1 @@******************"
echo "			  ***********###########*****************\033[0m\n"
	}
else
	{
echo "\033[44;33m			  ************=======********************"
echo "			*************||WINNER||********************"
echo "			***********@@ $pl2 @@******************"
echo "			  ***********###########*****************\033[0m\n"
	}
fi

## PRINT PARTIES

echo "\033[42;30mDo you want to see a round's fight? yes/no\033[0m"
read varparti
if [ $varparti == "yes" ]
then
	{
	echo "\033[42;30mWhich round do youwant to visualize? 1 to 5?\033[0m"
	read varround
	cat FIGHT_$varround
	}
fi


## DELET PARTIES
echo "\033[42;30mDo you want to delete all fights? yes/no\033[0m"
read vardel
if [ $vardel == "yes" ]
then
	rm -rf FIGHT_*
else
	{
	echo "\033[42;30mDo you want to see a round's fight? yes/no\033[0m"
	read varparti
	if [ $varparti == "yes" ]
	then
		{
		echo "\033[42;30mWhich round do you want to visualize? 1 to 5?\033[0m"
		read varround
		cat FIGHT_$varround
		}
	fi
	}
fi

## CLEAN FILEs
echo "DELETING TOTAL AND SCORE"
rm o x score $x


## CLEAN LIBRARY
echo "\n"
echo "CLEANING FILES"
make fclean

## End of the game
