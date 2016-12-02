#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>

using namespace std;

class Bar
{
	public:
		Bar();
	private:
		int menu();
		void leave();
		string randomNight(int rank);
		int drunkeness;
		int hype;
};

Bar::Bar()
{
	drunkeness = 0;
	hype = 0;
	while (true)
	{
		int choice = menu();
		if (choice == 1)
		{
			drunkeness += 10;
		}
		else if (choice == 2)
		{
			drunkeness += 5;
			hype += 10;
		}
		else if (choice == 3)
		{
			leave();
			break;
		}
	}
}

int Bar::menu()
{
	int x = 0, y = 0;
	cout << "   Welcome to the Drunken Clam!!!\n\n"
		 << "1. \"Pour me a pint of the dark stuff!\"\n"
		 << "2. \"Hey everyone! Next round's on me!\"\n"
		 << "3. \"Alright guys, I'm a head home...\n"
		 << "    Whatever happens happens.  G'night!\"\n" << endl;
	if (drunkeness >= 100) { x = 100; } else { x = drunkeness; }
	if (hype >= 100) { y = 100; } else { y = hype; }
	cout << "Drunkeness: " << x << "	Bar Hype: " << y << endl << endl;
	cout << "Choice::	";
	int choice = 0;
	cin >> choice;
	return choice;
}

void Bar::leave()
{
	int avgNight = (drunkeness + hype) / 2;
	if (avgNight > 80)
	{
		cout << randomNight(3) << endl;
	}
	else if (avgNight > 50)
	{
		cout << randomNight(2) << endl;
	}
	else if (avgNight > 20)
	{
		cout << randomNight(1) << endl;
	}
	else
	{
		cout << "You had a decent night\n"
			 << "but you went home basically sober...\n" << endl;
	}
	drunkeness = 0;
	hype = 0;
}

string Bar::randomNight(int rank)
{
	double randNum = (double)rand()/RAND_MAX;
	int index = (int)round(3 * randNum);
	if (drunkeness == 100 && hype == 0)
	{
		return "You Killed Mufasa!";
	}
    else if (rank == 1)
    {
        string rank1[4] =
        {
            "After drinking A LOT of drinks, you waited for 1 1/2 hours for\na bus ride home. You finally had to pee really badly and though you\ntried to hold it, you just couldn’t. You told your friend that you\nhad to pee and since he had a extra drink on the bus, he handed it to\nyou. You laid down on the bus seat and peed into it. It was small and\nhard to aim into but despite being as drunk as you were, you managed\nto mostly fill it. You also ended up peeing down the bus seats onto the\nfloor. After that, you carried the bottle with you out of the bus passing\nseveral people. You passed out on your couch upon arriving home.",
            "It seems you had waaaay too much to drink and got shit-faced.\nYou and your drunk friends left the bar and ran all around town.\nWhile climbing a tree you almost fell into a electric fence.\nDuring a drunk game of hide and seek, you forgot you were playing and\ntalked to a concrete wall for 20 minutes.  A nearby horse joined the conversation\nafter roughly 5 minutes of intense debate with the wall.  Finally, to end the night,\nyou crawled around on the ground, eating pansy flowers off the ground all the while\ntalking about salad and pub subs. Finally you passed out on your couch at home.",
            "You drank so much last night that when you came home, you decided\nto take all the flowers and plant pots from your neighbors garden.\nYou awoke the next morning with mud on your face and plants all around.",
            "Last night, you got so drunk that you decided to jump off your\ntoilet and dive face first into your cat’s litter box.  Your cat\nhas still not forgiven you."
        };
        return rank1[index];
    }
    else if (rank == 2)
    {
        string rank2[4] =
        {
            "Drunk as an irish sailor, you left the Drunken Clam and walked\nto a nearby festival taking place.  You wanted to get my hair bleached\nbut since they didn’t have bleach, you ended up getting your nose pierced.\nBest...Life...Decision...Ever.",
            "You got so drunk that you decided to ask your friend to borrow\ntheir phone. You then decided to text yourself asking if you were\nok and where you were...",
            "You are apparently a romantic drunk. After leaving the bar last night\nyou were so drunk that you stole a shovel and started digging out a\nstreet sign shouting, \"Jane I love you! I’ll give you this street\nsign as a gift!\" You then realized that the sign had a 100kg concrete\nweight underground. You actually dug out the whole thing and tried to\npull out the sign while screaming for help. Suddenly a car came by and\nthe driver asked what the hell you were doing. You replied heroically,\n\"I’m trying to be compelling to a girl. I'm the compellator!\"",
            "Last night you invited everyone at the bar to your place for a party.\nYou became so intoxicated that you left the party you were throwing\nwhen your parents showed up out of nowhere. You started claiming they\nwere undercover cops and started calling friends to come pick you up\nbecause your parents were about to arrest you. You threw your phone\nand keys because you thought they were tracking you and finally woke\nup the next morning in a ditch about a mile and a half from home. "
        };
        return rank2[index];
    }
    else if (rank == 3)
    {
        string rank3[4] =
        {
            "One night after drinking a lot, you wondered if I could walk\naround the block naked without being seen. It was a valiant attempt\nbut you couldn't make it. A bunch of girls pointed at you and laughed\nat your drunken nakedness. It was that night you became aware that you are\nnot well endowed. You passed out just inside your front door, still naked.",
            "After a few drinks at the bar, you and a few friends left for a party.\nSlowly, all the champagne bottles started to go missing. A little later on,\nA friend of yours saw you sneaking around in the dark, in the back yard, and in the snow,\nwearing only a bra and panties, quietly laughing to yourself, with all\nthe missing champagne bottles. You were very satisfied with yourself. Your\nfriend called your name and in a panic, you ran away.  It took 45 minutes to find you\nYou were hiding in a shed, butt-naked, and crying.",
            "Last night you got so drunk that you blacked out. In the time you were\nout, you ran laps around the local college campus screaming breaking bad\nlines, endlessly recited shakespeare in an attempt to try and prove you\nwere sober enough for more alcohol, tried to pick a fight with a 300\npound football player for “looking like a baboon”, started claiming you\nwere a CIA agent, puked everywhere, stripped to your underwear, ripped\nthe paper towel dispenser off the wall of a bathroom and fell asleep\non the bathroom floor. That'll be one for the grandkids one day.",
            "You and your wingman got plastered last night and got ripped off by\na gap toothed hooker. The police ended up dragging you from the wrong\nmotel room and driving the two of you back home where you stayed up till\nfive in the morning only to contemplate the origin of the period blood\non the motel bed and the locations of your missing wallets.  You woke up\ntwo hours later for work and are now still half drunk and strung out on\ncaffeine pills to get you through."
        };
        return rank3[index];
    }
    else { return ""; }
}


