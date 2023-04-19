/* Name: Hyenne Audrey L. Lim */
/* Section: S12A */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int displayStart ()
{
 /*
 Description: Displays the title Screen

 Parameters: null

 Return value:
 nStart - Returns 1 to start the game or 2 to end the game
 */

 int nStart;

 printf ("%s%s%s%s%s%s\n", "----------", "----------", "----------",
"----------", "----------", "----------");
 printf ("%35s\n", "WELCOME TO");
 printf ("%40s\n", "OILBULARYO ON THE GO!");
 printf ("%s%s%s%s%s%s\n", "----------", "----------", "----------",
"----------", "----------", "----------");
 printf ("\n1. Start Sales Trip\n");
 printf ("2. Exit Game\n");
 printf ("\nChoose option 1 or 2: ");
 scanf ("%d", &nStart);
 while (nStart > 2 || nStart < 1)
 scanf ("%d", &nStart);
 return nStart;
}
void displayDetails (int nDay, int nCash, int nDebt, char* cLocation, int nCharge)
{
 /*
 Description: Displays the player's details per day

 Parameters:
 int nDay - to display the current day number
 int nCash - to display the amount of cash the player has
 int nDebt - to display the amount of debt the player has
 char* cLocation - to display the current location
 int nCharge - To display the charge to make diffuser oils in the current
location.

 Return value: void
 */

 printf ("Day %d", nDay); // Shows day number //
 printf ("\nLocation: %s", cLocation); // Shows location //
 printf ("\nCash: $%d", nCash); // Shows the amount of cash the player currently has //
 printf ("\nDebt: $%d", nDebt); // Shows the amount of debt the player currentlyhas //
 printf ("\nCity Charge: $%d", nCharge); // Shows the cost of charge for making diffuser oils in the location //
}
int computeDebt (int nDebt, int nDay)
{
 /*
 Description: Computes the current debt and returns debt with interest.

 Parameters:
 int nDebt - Current debt to compute with interest
 int nDay - To make sure the interest will not be added on the first day.

 Return value: nComputedDebt is the updated value for nDebt
 */
 int nComputedDebt;

 if (nDay > 1) //The interest will only be added after day 1//
 nComputedDebt = nDebt * 1.10;

 else
 nComputedDebt = nDebt; //To make sure that the interest will not be added to the debt at the start of the game//

 return nComputedDebt;
}
void computeAverageEssOil (int nLemon, int nRoseM, int nMint, int nLavender, int
nLemonPrice, int nRoseMPrice, int nMintPrice, int nLavenderPrice, int* nAveLemon,
int* nAveRoseM, int* nAveMint, int* nAveLavender, int* nNewLemon, int* nNewRoseM,
int* nNewMint, int* nNewLavender)
{
 /*
 Description: The function computes the average price per drop of essential
oil and updates the variable
 Parameters:
 int nLemon - The amount of lemon drops the player has.
 int nRoseM - The amount of rosemary drops the player has.
 int nMint - The amount of mint drops the player has.
 int nLavender - The amount of lavender drops the player has.
 int nLemonPrice - The price per lemon bottle.
 int nRoseMPrice - The price per rosemary bottle.
 int nMintPrice - The price per mint bottle.
 int nLavenderPrice - The price per lavender bottles.
 int* nAveLemon - The average price per drop of lemon.
 int* nAveRoseM - The average price per drop of rosemary.
 int* nAveMint - The average price per drop of mint.
 int* nAveLavender The average price per drop of lavender.
 int* nNewLemon - The newly acquired drops of lemon to be resetted to 0
after getting the average.
 int* nNewRoseM - The newly acquired drops of rosemary to be resetted to 0
after getting the average.
 int* nNewMint - The newly acquired drops of mint to be resetted to 0 after
getting the average.
 int* nNewLavender The newly acquired drops of lavender to be resetted to 0
after getting the average.

 Return value: void
 */

 //Average price per lemon drop//
 if (nLemon == 0)
 *nAveLemon = 0; //To prevent error if the divisor is 0//
 else
 *nAveLemon = (*nAveLemon * (nLemon - *nNewLemon) + *nNewLemon *
(nLemonPrice / 10)) / nLemon;

 //Average price per rosemary drop//
 if (nRoseM == 0)
 *nAveRoseM = 0; //To prevent error if the divisor is 0//
 else
 *nAveRoseM = (*nAveRoseM * (nRoseM - *nNewRoseM) + *nNewRoseM *
(nRoseMPrice / 10)) / nRoseM;

 //Average price per mint drop//
 if (nMint == 0)
 nAveMint = 0; //To prevent error if the divisor is 0//
 else
 *nAveMint = (*nAveMint * (nMint - *nNewMint) + *nNewMint * (nMintPrice /
10)) / nMint;

 //Average price per lavender drop//
 if (nLavender == 0)
 *nAveLavender = 0; //To prevent error if the divisor is 0//
 else
 *nAveLavender = (*nAveLavender * (nLavender - *nNewLavender) +
*nNewLavender * (nLavenderPrice / 10)) / nLavender;

 //Resetting the values to zero//
 nNewLemon = 0;
 nNewRoseM = 0;
 nNewMint = 0;
 nNewLavender = 0;
}
void computeAverageDiffOil (int nClearM, int nEnergyB, int nCalming, int*
nAveClearM, int* nAveEnergyB, int* nAveCalming, int nAveLemon, int nAveRoseM, int
nAveMint, int nAveLavender, int nCharge)
{
 /*
 Description: Computes the average price per drop of diffuser oil and
updates the variables.
 Parameters:
 int nClearM - The number of Clear Mind bottles.
 int nEnergyB - The number of Energy bottles.
 int nCalming - The number of Calming bottles.
 int* nAveClearM - The average price per bottle of Clear Minds.
 int* nAveEnergyB - The average price per bottle of Energy Booster.
 int* nAveCalming - The average price per bottle of Calming.
 int nAveLemon - The average price per drop of lemon.
 int nAveRoseM - The average price per drop of rosemary.
 int nAveMint - The average price per drop of mint.
 int nAveLavender - The average price per drop of lavender.
 int nCharge - The charge to make diffuser oils.

 Return value: None
 */

 //Average price per Clear Minds bottle//
 if (nClearM == 0)
 *nAveClearM = 0; //To prevent error if the divisor is 0//
 else
 *nAveClearM = (nClearM * 3 * nAveLemon + nClearM * 2 * nAveRoseM + nClearM
* 2 * nAveMint + nCharge) / nClearM;

 //Average price per Energy Booster bottle//
 if (nEnergyB == 0)
 *nAveEnergyB = 0; //To prevent error if the divisor is 0//
 else
 *nAveEnergyB = (nEnergyB * nAveLemon + nEnergyB * nAveRoseM + nEnergyB *
nAveMint + nCharge) / nEnergyB;

 //Average price per Calming bottle//
 if (nCalming == 0)
 *nAveCalming = 0; //To prevent error if the divisor is 0//
 else
 *nAveCalming = (nCalming * nAveLemon + nCalming * 2 * nAveRoseM + nCalming
* 3 * nAveLavender + nCharge) / nCalming;
}
void generateEssOilPrice (int* nLemonPrice, int* nRoseMPrice, int* nMintPrice, int*
nLavenderPrice)
{
 /*
 Description: The function randomly generates a factor and adds, subtracts,
or is multiplied to the value based on the chance generated.
 Parameters:
 int* nLemonPrice - The price of lemon that will be randomly generated.
 int* nRoseMPrice - The price of rosemary that will be randomly generated.
 int* nMintPrice - The price of mint that will be randomly generated.
 int* nLavenderPrice - The price of lavender that will be randomly
generated.

 Return value: void
 */

 int nOperator;
 int nNum;

 srand ((unsigned int) time(0));

 nNum = rand() % 98 + 102;

 // Generating the operator for lemon//
 nOperator = rand() % 100;

 if (nOperator >= 0 && nOperator <= 34) // Addition//
 *nLemonPrice = rand () % 51 + 100 + nNum;

 if (nOperator >= 35 && nOperator <= 69) //Subtraction//
 *nLemonPrice = rand () % 51 + 100 - nNum;

 if (nOperator >= 70 && nOperator <= 89) //Multiplication//
 *nLemonPrice = (rand () % 51 + 100) * nNum;

 if (nOperator >= 90 && nOperator <= 99) //Retain the value//
 *nLemonPrice = rand () % 51 + 100;


 // Generating the operator for rosemary//
 nOperator = rand() % 100;

 if (nOperator >= 0 && nOperator <= 34) //Addition//
 *nRoseMPrice = rand () % 31 + 70 + nNum;

 if (nOperator >= 35 && nOperator <= 69) //Subtraction//
 *nRoseMPrice = rand () % 31 + 70 - nNum;

 if (nOperator >= 70 && nOperator <= 89) //Multiplication//
 *nRoseMPrice = (rand () % 31 + 70) * nNum;

 if (nOperator >= 90 && nOperator <= 99) //Retain the value//
 *nRoseMPrice = rand () % 31 + 70;

 // Generating the operator for mint//
 nOperator = rand() % 100;

 if (nOperator >= 0 && nOperator <= 34) //Addition//
 *nMintPrice = rand () % 71 + 130 + nNum;

 if (nOperator >= 35 && nOperator <= 69) //Subtraction//
 *nMintPrice = rand () % 71 + 130 - nNum;

 if (nOperator >= 70 && nOperator <= 89) //Multiplication//
 *nMintPrice = (rand () % 71 + 130) * nNum;

 if (nOperator >= 90 && nOperator <= 99) //Retain the value//
 *nMintPrice = rand () % 71 + 130;

 // Generating the operator for lavender//
 nOperator = rand() % 100;

 if (nOperator >= 0 && nOperator <= 34) // Addition//
 *nLavenderPrice = rand () % 41 + 20 + nNum;
 if (nOperator >= 35 && nOperator <= 69) //Subtraction//
 *nLavenderPrice = rand () % 41 + 20 - nNum;

 if (nOperator >= 70 && nOperator <= 89) //Multiplication//
 *nLavenderPrice = (rand () % 41 + 20) * nNum;
 if (nOperator >= 90 && nOperator <= 99) //Retain the value//
 *nLavenderPrice = rand () % 41 + 20;

 // Making the price of the essential 0 if price generated is negative//

 if (*nLemonPrice <= 0)
 *nLemonPrice = 0;
 if (*nRoseMPrice <= 0)
 *nRoseMPrice = 0;
 if (*nMintPrice <= 0)
 *nMintPrice = 0;
 if (*nLavenderPrice <= 0)
 *nLavenderPrice = 0;

}
void computeDiffOilPrice (int* nClearMPrice, int* nEnergyBPrice, int*
nCalmingPrice, int nLemonPrice, int nRoseMPrice, int nMintPrice, int
nLavenderPrice)
{
 /*
 Description: The function computes the price of each diffuser oil.
 Parameters:
 int* nClearMPrice - The price of each Clear Minds bottle that will be
updated.
 int* nEnergyBPrice - The price of each Energy Booster bottle that will be
updated.
 int* nCalmingPrice - The price of each Calming bottle that will be updated.
 int nLemonPrice - The price of each lemon bottle that will be computed to
the price of diffuser oils.
 int nRoseMPrice - The price of each rosemary bottle that will be computed
to the price of diffuser oils.
 int nMintPrice - The price of each mint bottle that will be computed to the
price of Clear minds and Energy Booster
 int nLavenderPrice - The price of each lavender bottle that will be
computed to the price of Calming.

 Return value: void
 */

 // Price of each drop of essential oil//
 int nLemonDropPrice = nLemonPrice / 10;
 int nRoseMDropPrice = nRoseMPrice / 10;
 int nMintDropPrice = nMintPrice / 10;
 int nLavenderDropPrice = nLavenderPrice / 10;

 // Computation for the price of each diffuser oil//
 *nClearMPrice = (3 * nLemonDropPrice + 2 * nRoseMDropPrice + 2 *
nMintDropPrice) * 1.15;
 *nEnergyBPrice = (nLemonDropPrice + nRoseMDropPrice + nMintDropPrice) * 1.15;
 *nCalmingPrice = (3 * nLavenderDropPrice + 2 * nRoseMDropPrice +
nLemonDropPrice) * 1.15;
}
void generateFreebieChance (int* nLemon, int* nRoseM, int* nMint, int* nLavender,
int* nClearM, int* nEnergyB, int* nCalming)
{
 /*
 Description: The function generates a chance to get a freebie and updates
the stock on hand when the player receives it.

 Parameters:
 int* nLemon - The amount of lemon drops that will be updated if the player
wins one bottle.
 int* nRoseM - The amount of rosemary drops that will be updated if the
player wins one bottle.
 int* nMint - The amount of mint drops that will be updated if the player
wins one bottle.
 int* nLavender - The amount of lavender drops that will be updated if the
player wins one bottle.
 int* nClearM - The number of Clear Minds bottle that will be updated if the
player wins one bottle.
 int* nEnergyB - The number of Energy booster bottle that will be updated if
the player wins one bottle.
 int* nCalming - The number of Calming bottle that will be updated if the
player wins one bottle.

 Return value: void
 */

 int nChance;
 int nContinue = 0;
 srand ((unsigned int)time(0));

 nChance = rand () % 100;

 //Chance Generator for freebies//
 if (nChance >= 0 && nChance <= 9) // 10% chance to get one bottle of lemon//
 {
 *nLemon += 10;
 printf ("You received 1 bottle of lemon for free. ");
 }

 if (nChance >= 10 && nChance <= 19) // 10% chance to get one bottle of rosemary//
 {
 *nRoseM += 10;
 printf ("You received 1 bottle of rosemary for free. ");
 }

 if (nChance >= 20 && nChance <= 29) // 10% chance to get one bottle of mint//
 {
 *nMint += 10;
 printf ("You received 1 bottle of mint for free. ");
 }

 if (nChance >= 30 && nChance <= 39) // 10% chance to get one bottle of lavender//
 {
 *nLavender += 10;
 printf ("You received 1 bottle of lavender for free. ");
 }

 if (nChance >= 40 && nChance <= 49)// 10% chance to get one bottle of Clear Mind//
 {
 *nClearM += 1;
 printf ("You received 1 bottle of Clear Minds for free. ");
 }

 if (nChance >= 50 && nChance <= 59) // 10% chance to get one bottle of Energy Booster//
 {
 *nEnergyB += 1;
 printf ("You received 1 bottle of Energy Booster for free. ");
 }

 if (nChance >= 60 && nChance <= 69) // 10% chance to get one bottle of Calming//
 {
 *nCalming += 1;
 printf ("You received 1 bottle of Calming for free. ");
 }

 if (nChance >= 70 && nChance <= 99) // 10% chance to not win anything//
 printf ("Sadly, you didn't win any freebies. ");

 printf ("Press 1 to continue. ");

 while (nContinue != 1)
 {
 scanf ("%d", &nContinue);
 }
}
void generateCityCharge (int nLocation, int* nCharge)
{
 /*
 Description: The function computes the charge based on the location.

 Parameters:
 int nLocation - The charge will be based on player's current location.
 int* nCharge - The variable that will be updated after generating a random
price.

 Return value: void
 */

 srand ((unsigned int)time(0));

 if (nLocation == 1) //The charge to make diffuser oil in Manila//
 *nCharge = rand () % 11 + 20;

 if (nLocation == 2) //The charge to make diffuser oil in Makati//
 *nCharge = rand () % 21 + 80;

 if (nLocation == 3) //The charge to make diffuser oil in Alabang//
 *nCharge = rand () % 21 + 70;

 if (nLocation == 4) //The charge to make diffuser oil in Quezon City//
 *nCharge = rand () % 21 + 40;
}
void displayInventory (int nLemon, int nRoseM, int nMint, int nLavender, int
nClearM, int nEnergyB, int nCalming, int nLemonPrice, int nRoseMPrice, int
nMintPrice, int nLavenderPrice, int nClearMPrice, int nEnergyBPrice, int
nCalmingPrice, int nAveLemon, int nAveRoseM, int nAveMint, int nAveLavender, int
nAveClearM, int nAveEnergyB, int nAveCalming)
{
 /*
 Description: Displays the player's inventory

 Parameters:
 int nLemon - To display the amount of lemon drops
 int nRoseM - To display the amount of rosemary drops
 int nMint - To display the amount of mint drops
 int nLavender - To display the amount of lavender drops
 int nClearM - To display the number of Clear minds bottles
 int nEnergyB - To display the number of Energy Booster bottles
 int nCalming - To display the number of Calming bottles
 int nLemonPrice - To display the price of lemon drops
 int nRoseMPrice - To display the price of rosemary drops
 int nMintPrice - To display the price of mint drops
 int nLavenderPrice - To display the price of lavender drops
 int nClearMPrice - To display the price of Clear minds
 int nEnergyBPrice - To display the price of Energy Booster
 int nCalmingPrice - To display the price of Calming
 int nAveLemon - To display the average price per lemon drop.
 int nAveRoseM - To display the average price per rosemary drop.
 int nAveMint - To display the average price per mint drop.
 int nAveLavender - To display the average price per lavender drop.
 int nAveClearM - To display the average price per bottle of Clear Minds.
 int nAveEnergyB - To display the average price per bottle of Energy
Booster.
 int nAveCalming - To display the average price per bottle of Calming.
 Return value: void
 */

 printf ("\n%s%s%s%s%s%s\n", "==========", "==========", "==========",
"==========", "==========", "==========");
 printf ("%34s", "Inventory");
 printf ("\n%s%s%s%s%s%s\n", "==========", "==========", "==========",
"==========", "==========", "==========");
 printf ("%s%46s", "Essential Oils", "Buy/Sell Price");

 printf ("\n%s%s%s%s%s%s\n", "----------", "----------", "----------",
"----------", "----------", "----------");
 printf ("%-20s%5d%9s$%6d%10s%-11d", "1. Lemon", nLemon, " drops @", nAveLemon,
"/drop ", nLemonPrice);
 printf ("\n%s%s%s%s%s%s\n", "----------", "----------", "----------",
"----------", "----------", "----------");
 printf ("%-20s%5d%9s$%6d%10s%-11d", "2. Rosemary", nRoseM, " drops @",
nAveRoseM, "/drop ", nRoseMPrice);
 printf ("\n%s%s%s%s%s%s\n", "----------", "----------", "----------",
"----------", "----------", "----------");
 printf ("%-20s%5d%9s$%6d%10s%-11d", "3. Mint", nMint, " drops @", nAveMint, "/drop ", nMintPrice);
 printf ("\n%s%s%s%s%s%s\n", "----------", "----------", "----------",
"----------", "----------", "----------");
 printf ("%-20s%5d%9s$%6d%10s%-11d", "4. Lavender", nLavender, " drops @",
nAveLavender, "/drop ", nLavenderPrice);

 printf ("\n%s%s%s%s%s%s\n", "==========", "==========", "==========",
"==========", "==========", "==========");
 printf ("%s%44s", "Diffuser Oils", "Sell Price");

 printf ("\n%s%s%s%s%s%s\n", "----------", "----------", "----------",
"----------", "----------", "----------");
 printf ("%-20s%5d%8s$%6d%9s%-11d", "5. Clear Minds", nClearM, " btls @",
nAveClearM, "/drop ", nClearMPrice);
 printf ("\n%s%s%s%s%s%s\n", "----------", "----------", "----------",
"----------", "----------", "----------");
 printf ("%-20s%5d%8s$%6d%9s%-11d", "6. Energy Booster", nEnergyB, " btls @",
nAveEnergyB, "/drop ", nEnergyBPrice);
 printf ("\n%s%s%s%s%s%s\n", "----------", "----------", "----------",
"----------", "----------", "----------");
 printf ("%-20s%5d%8s$%6d%9s%-11d", "7. Calming", nCalming, " btls @",
nAveCalming, "/drop ", nCalmingPrice);
 printf ("\n%s%s%s%s%s%s\n\n\n", "==========", "==========", "==========",
"==========", "==========", "==========");
}
void chooseBuy (int nLemonPrice, int nLavenderPrice, int nRoseMPrice, int
nMintPrice, int* nLemon, int* nLavender, int* nRoseM, int *nMint, int *nCash, int*
nNewLemon, int* nNewRoseM, int* nNewMint, int* nNewLavender)
{
 /*
 Description: The function updates the stock on hand and cash when the
player chooses to buy.

 Parameters:
 int nLemonPrice - The price per bottle of lemon
 int nLavenderPrice - The price per bottle of lavender
 int nRoseMPrice - The price per bottle of rosemary
 int nMintPrice - The price per bottle of mint
 int* nLemon - To update the amount of lemon drops if the player decides to
buy
 int* nLavender - To update the amount of lavender drops if the player
decides to buy
 int* nRoseM - To update the amount of rosemary drops if the player decides
to buy
 int *nMint - To update the amount of mint drops if the player decides to
buy
 int *nCash - To subtract and update the cash after buying
 int* nNewLemon - The newly acquired lemon drops to be used for computing
the average price per drop
 int* nNewRoseM - The newly acquired rosemary drops to be used for computing
the average price per drop
 int* nNewMint - The newly acquired mint drops to be used for computing the
average price per drop
 int* nNewLavender - The newly acquired lavender drops to be used for
computing the average price per drop

 Return value: void
 */

 int nChoice;
 int nQuantity;
 int nExit = 0;

 printf ("\n(1) Lemon, (2) Rosemary, (3) Mint, (4) Lavender, or (0) Nothing.\
n");
 printf ("What do you want to buy? ");
 scanf ("%d", &nChoice);

 while (nChoice < 0 || nChoice > 5) //Loops if the number entered is not valid//
 {
 scanf ("%d", &nChoice);
 }

 if (nChoice == 1) //Player chooses to buy lemon drops//
 {
 if (nLemonPrice == 0)
 {
 printf ("\nThere is no available stock. Press 1 to continue. "); // If the price of lemon is 0, no stock available in the city//

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
 else
 {
 printf ("\nYou can buy %d bottles of lemon.\n", *nCash /
nLemonPrice); // The max number of lemon bottles the player can buy //
 printf ("How many bottles do you want to buy? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > *nCash / nLemonPrice || nQuantity < 0) //To make sure that the player will make a valid purchase//
 {
 if (nQuantity > *nCash / nLemonPrice)
 printf ("You don't have enough money.");

 if (nQuantity < 0)
 printf ("Enter a valid number. ");

 scanf ("%d", &nQuantity);
 }

 *nLemon += nQuantity * 10; // Convert to drops and update the stock on hand //
 *nCash -= nQuantity * nLemonPrice; // Update the cash after buying //
 *nNewLemon = nQuantity * 10; //Add the newly acquired batch//
 }
 }

 if (nChoice == 2) //Player chooses to buy rosemary drops//
 {
 if (nRoseMPrice == 0)
 {
 printf ("\nThere is no available stock. Press 1 to continue. "); // If the price of rosemary is 0, no stock available in the city//

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
 else
 {
 printf ("\nYou can buy %d bottles of rosemary.\n", *nCash /
nRoseMPrice); // The max number of rosemary bottles the player can buy //
 printf ("How many bottles do you want to buy? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > *nCash / nRoseMPrice || nQuantity < 0) //To make sure that the player will make a valid purchase//
 {
 if (nQuantity > *nCash / nRoseMPrice)
 printf ("You don't have enough money.");

 if (nQuantity < 0)
 printf ("Enter a valid number. ");

 scanf ("%d", &nQuantity);
 }
 *nRoseM += nQuantity * 10; //Convert to drops and update the stock on hand//
 *nCash -= nQuantity * nRoseMPrice; //Update the cash after buying //
 *nNewRoseM = nQuantity * 10; // Add the newly acquired batch //
 }
 }
 if (nChoice == 3) //Player chooses to buy mint drops//
 {
 if (nMintPrice == 0)
 {
 printf ("\nThere is no available stock. Press 1 to continue. "); // If the price of mint is 0, no stock available in the city//

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
 else
 {
 printf ("\nYou can buy %d bottles of mint.\n", *nCash / nMintPrice); // The max number of mint bottles the player can buy //
 printf ("How many bottles do you want to buy? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > *nCash / nMintPrice || nQuantity < 0) //To make sure that the player will make a valid purchase//
 {
 if (nQuantity > *nCash / nMintPrice)
 printf ("You don't have enough money.");

 if (nQuantity < 0)
 printf ("Enter a valid number. ");

 scanf ("%d", &nQuantity);
 }
 *nMint += nQuantity * 10; //Convert to drops and update the stock on hand//
 *nCash -= nQuantity * nMintPrice; //Update the cash after buying //
 *nNewMint = nQuantity * 10; // Add the newly acquired batch //
 }
 }
 if (nChoice == 4) //Player chooses to buy lavender drops//
 {
 if (nLavenderPrice == 0)
 {
 printf ("\nThere is no available stock. Press 1 to continue. "); // If the price of lavender is 0, no stock available in the city//

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
 else
 {
 printf ("\nYou can buy %d bottles of lavender.\n", *nCash /
nLavenderPrice); // The max number of lavender bottles the player can buy //
 printf ("How many bottles do you want to buy? ");
 scanf ("%d", &nQuantity);
 while (nQuantity > *nCash / nLavenderPrice || nQuantity < 0) //To make sure that the player will make a valid purchase//
 {
 if (nQuantity > *nCash / nLavenderPrice)
 printf ("You don't have enough money.");

 if (nQuantity < 0)
 printf ("Enter a valid number. ");

 scanf ("%d", &nQuantity);
 }
 *nLavender += nQuantity * 10; //Update the stock on hand//
 *nCash -= nQuantity * nLavenderPrice; //Convert to drops and update the cash after buying //
 *nNewLavender = nQuantity * 10; // Add the newly acquired batch //
 }
 }

 if (nChoice == 0) //Player chooses to not buy anything//
 {
 printf ("You chose to not buy anything. Press 1 to exit. "); // The player decides to not buy anything and the exit message will display//
 while (nExit != 1)
 {
 scanf ("%d", &nExit);
 }
 }
}

void chooseSell (int nLemonPrice, int nLavenderPrice, int nRoseMPrice, int
nMintPrice, int nEnergyBPrice, int nCalmingPrice, int nClearMPrice, int* nLemon,
int* nLavender, int* nRoseM, int* nMint, int* nEnergyB, int* nClearM, int*
nCalming, int* nCash)
{
 /*
 Description: The function updates the stock on hand and cash when the
player chooses to sell.

 Parameters:
 int nLemonPrice - The price per lemon bottle to be converted to per drop
 int nLavenderPrice - The price per lavender bottle to be converted to per
drop
 int nRoseMPrice - The price per rosemary bottle to be converted to per drop
 int nMintPrice - The price per mint bottle to be converted to per drop
 int nEnergyBPrice - The price per Energy booster bottle
 int nCalmingPrice - The price per Calming bottle
 int nClearMPrice - The price per Clear Minds bottle
 int* nLemon - To update the amount of lemon drops if the player decides to
sell.
 int* nLavender - To update the amount of lavender drops if the player
decides to sell.
 int* nRoseM - To update the amount of rosemary drops if the player decides
to sell.
 int* nMint - To update the amount of mint drops if the player decides to
sell.
 int* nEnergyB - To update the number of Energy Booster bottles if the
player decides to sell.
 int* nClearM - To update the number of Clear Minds bottles if the player
decides to sell.
 int* nCalming - To update the number of Calming bottles if the player
decides to sell.
 int* nCash - To add and update cash after selling.

 Return value: None
 */

 int nChoice;
 int nQuantity;
 int nExit = 0;
 printf ("\n(1) Lemon, (2) Rosemary, (3) Mint, (4) Lavender, (5) Clear Minds, (6) Energy Booster, (7) Calming, or (0) I don't want to sell anything.\n");
 printf ("What do you want to sell? ");
 scanf ("%d", &nChoice);

 while (nChoice < 0 || nChoice > 7) //Loops if entered number is invalid //
 {
 printf ("Enter a valid number. ");
 scanf ("%d", &nChoice);
 }

 if (nChoice == 1) //Player chooses to sell lemon drops//
 {
 if (*nLemon <= 0)
 {
 printf ("\nYou don't have enough drops of lemon to sell. Press 1 to exit. "); // Exit if the player doesn't have any drops of lemon //

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
 else
 {
 printf ("\nYou have %d drops of lemon.\n", *nLemon); // Displays the amount of lemon drops the player has //
 printf ("How many do you want to sell? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > *nLemon || nQuantity < 0) //Makes sure that the player is making a valid transaction//
 {
 printf ("Enter a valid input. ");
 scanf ("%d", &nQuantity);
 }
 *nLemon -= nQuantity; // Subtract the amount sold //
 *nCash += nQuantity * (nLemonPrice / 10); // Update the cash after selling //
 }
 }
 if (nChoice == 2) //Player chooses to sell rosemary drops//
 {
 if (*nRoseM <= 0)
 {
 printf ("\nYou don't have enough drops of rosemary to sell. Press 1 to exit "); // Exit if the player doesn't have any drops of rosemary //

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
 else
 {
 printf ("\nYou have %d drops of rosemary.\n", *nRoseM); // Displays the amount of rosemary drops the player has //
 printf ("How many do you want to sell? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > *nRoseM || nQuantity < 0) //Makes sure that the player is making a valid transaction//
 {
 printf ("Enter a valid input. ");
 scanf ("%d", &nQuantity);
 }

 *nRoseM -= nQuantity; // Subtract the amount sold //
 *nCash += nQuantity * (nRoseMPrice / 10); // Update the cash after selling //
 }
 }
 if (nChoice == 3) //Player chooses to sell mint drops//
 {
 if (*nMint <= 0)
 {
 printf ("\nYou don't have enough drops of mint to sell. Press 1 to exit."); // Exit if the player doesn't have any drops of mint //

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
 else
 {
 printf ("\nYou have %d drops of mint.\n", *nMint); // Displays the amount of mint drops the player has //
 printf ("How many do you want to sell? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > *nMint || nQuantity < 0) //Makes sure that the player is making a valid transaction//
 {
 printf ("Enter a valid input. ");
 scanf ("%d", &nQuantity);
 }
 *nMint -= nQuantity; // Subtract the amount sold //
 *nCash += nQuantity * (nMintPrice / 10); // Update the cash after selling //
 }
 }

 if (nChoice == 4) //Player chooses to sell lavender drops//
 {
 if (*nLavender <= 0)
 {
 printf ("\nYou don't have enough drops of lavender to sell. Press 1 to exit. "); // Exit if the player doesn't have any drops of lavender //

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
 else
 {
 printf ("\nYou have %d drops of lavender.\n", *nLavender); // Displays the amount of lavender drops the player has //
 printf ("How many do you want to sell? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > *nLavender || nQuantity < 0) //Makes sure that the player is making a valid transaction//
 {
 printf ("Enter a valid input. ");
 scanf ("%d", &nQuantity);
 }
 *nLavender -= nQuantity; // Subtract the amount sold //
 *nCash += nQuantity * (nLavenderPrice / 10); // Update the cash after selling //
 }
 }
 if (nChoice == 5) //Player chooses to sell bottles of Clear Minds//
 {
 if (*nClearM <= 0)
 {
 printf ("\nYou don't have bottles of Clear Minds to sell. Press 1 to exit "); // Exit if the player doesn't have any bottles of Clear Minds //

 while (nExit != 1)
 scanf ("%d", &nExit);
 }

 else
 {
 printf ("\nYou have %d bottles of clear mind.\n", *nClearM); // Displays the number of Clear Mind bottles the player has //
 printf ("How many do you want to sell? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > *nClearM || nQuantity < 0) //Makes sure that the player is making a valid transaction//
 {
 printf ("Enter a valid input. ");
 scanf ("%d", &nQuantity);
 }

 *nClearM -= nQuantity; // Subtract the amount sold //
 *nCash += nQuantity * nClearMPrice; // Update the cash after selling //
 }
 }
 if (nChoice == 6) //Player chooses to sell bottles of Energy Booster//
 {
 if (*nEnergyB <= 0)
 {
 printf ("\nYou don't have bottles of Energy Booster to sell. Press 1 to exit. "); // Exit if the player doesn't have any bottles of Energy Booster //

 while (nExit != 1)
 scanf ("%d", &nExit);
 }

 else
 {
 printf ("\nYou have %d bottles of energy booster.\n", *nEnergyB); // Displays the number of Energy Booster bottles the player has //
 printf ("How many do you want to sell? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > *nEnergyB || nQuantity < 0) //Makes sure that the player is making a valid transaction//
 {
 printf ("Enter a valid input. ");
 scanf ("%d", &nQuantity);
 }

 *nEnergyB -= nQuantity; // Subtract the amount sold //
 *nCash += nQuantity * nEnergyBPrice; // Update the cash after selling //
 }
 }
 if (nChoice == 7) //Player chooses to sell bottles of Calming //
 {
 if (*nCalming <= 0)
 {
 printf ("\nYou don't have bottles of Calming to sell. "); // Exit if the player doesn't have any bottles of Calming //

 while (nExit != 1)
 scanf ("%d", &nExit);
 }

 else
 {
 printf ("\nYou have %d bottles of calming.\n", *nCalming); // Displays the number of Calming bottles the player has //
 printf ("How many do you want to sell? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > *nCalming || nQuantity < 0) //Makes sure that the player is making a valid transaction//
 {
 printf ("Enter a valid input. ");
 scanf ("%d", &nQuantity);
 }
 *nCalming -= nQuantity; // Subtract the amount sold //
 *nCash += nQuantity * nCalmingPrice; // Update the cash after selling //
 }
 }
 if (nChoice == 0) //Player chooses to not sell anything//
 {
 printf ("You chose to not sell anything. Press 1 to exit. "); //Exit when the player enters 0 in choices//

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
}
void chooseMakeDiffOil (int* nLemon, int* nRoseM, int* nMint, int* nLavender, int*
nCalming, int* nEnergyB, int* nClearM, int nCharge, int* nCash)
{
 /*
 Description: The function updates the inventory variables when the player
chooses to make diffuser oils.
 Parameters:
 int* nLemon - The amount of lemon drops to be updated if the player made
diffuser oils.
 int* nRoseM - The amount of rosemary drops to be updated if the player made
diffuser oils.
 int* nMint - The amount of mint drops to be updated if the player made
diffuser oils.
 int* nLavender - The amount of lavender drops to be updated if the player
made diffuser oils.
 int* nCalming - To update the amount of Calming bottles if the player
chooses to make more.
 int* nEnergyB - To update the amount of Energy booster bottles if the
player chooses to make more.
 int* nClearM - To update the amount of Clear Mind bottles if the player
chooses to make more.
 int nCharge - The charge to make diffuser oils
 int* nCash - To subtract the charge from the cash if the player makes
batches of diffuser oils.

 Return value: None
 */

 int nChoice;
 int nQuantity;
 int nExit = 0;

 //The max count of diffuser oils the player can make based on his inventory//
 int nClearMCount = 0;
 int nEnergyBCount = 0;
 int nCalmingCount = 0;
 printf ("\n"); //Add space//

 //Shows diffuser oils that can be made//
 if (*nLemon >= 3 && *nRoseM >= 2 && *nMint >= 2) //Show Clear Minds in the options if the player has enough ingredients//
 printf ("(1) Clear Minds ");

 if (*nLemon > 0 && *nRoseM > 0 && *nMint > 0) //Show Energy Booster in the options if the player has enough ingredients//
 printf ("(2) Energy Booster ");

 if (*nLemon >= 1 && *nRoseM >= 2 && *nLavender >= 3) //Show Calming in the options if the player has enough ingredients//
 printf ("(3) Calming ");

 printf ("(0) Nothing\n"); //Show option as default//

 printf ("What diffuser oils you want to make? ");
 scanf ("%d", &nChoice);
 while (nChoice < 0 || nChoice > 3)
 {
 scanf ("%d", &nChoice);
 }

 if (nChoice == 1) //Player chooses to make bottles of Clear Minds//
 {
 // Getting max bottles of Clear Minds the player can make //
 if (*nLemon / 3 <= *nRoseM / 2 && *nLemon / 3 <= *nMint / 2)
 nClearMCount = *nLemon / 3;

 if (*nRoseM / 2 <= *nLemon / 3 && *nRoseM / 2 <= *nMint / 2)
 nClearMCount = *nRoseM / 2;

 if (*nMint / 2 <= *nRoseM / 2 && *nMint / 2 <= *nLemon / 3)
 nClearMCount = *nMint / 2;

 //Check if player has enough cash to afford the charge//
 if (*nCash < nCharge)
 {
 printf ("\nYou don't have enough money to pay the charge. Press 1 to exit. ");

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
 else
 {
 printf ("\nYou can make %d bottles of Clear Minds.\n",
nClearMCount); //The max amount of Clear Minds bottles the player can make//
 printf ("How many bottles do you want to make? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > nClearMCount || nQuantity < 0) //Makes sure the player entered a valid number//
 {
 if (nClearMCount < nQuantity)
 printf ("You don't have enough ingredients to make that amount. ");
 if (nQuantity < 0)
 printf ("Enter a valid amount. ");

 scanf ("%d", &nQuantity);
 }

 //Adding new bottles of Clear Minds and subtracting the ingredients//
 *nClearM += nQuantity;
 *nLemon -= nQuantity * 3;
 *nRoseM -= nQuantity * 2;
 *nMint -= nQuantity * 2;

 //Charges the player if he makes diffuser oils and doesn't execute if the player chose to not make any diffuser oil//
 if (nQuantity > 0)
 *nCash -= nCharge;
 }
 }

 if (nChoice == 2) //Player chooses to make bottles of Energy Booster//
 {
 // Getting max bottles of Energy Booster the player can make //
 if (*nLemon <= *nRoseM && *nLemon <= *nMint)
 nEnergyBCount = *nLemon;

 if (*nRoseM <= *nLemon && *nRoseM <= *nMint)
 nEnergyBCount = *nRoseM;

 if (*nMint <= *nRoseM && *nMint <= *nLemon)
 nEnergyBCount = *nMint;

 //Check if the player has enough cash to pay the charge//
 if (*nCash < nCharge)
 {
 printf ("\nYou don't have enough money to pay the charge. Press 1 to exit. ");

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
 else
 {
 printf ("\nYou can make %d bottles of Energy Booster.\n",
nEnergyBCount); // Max amount of Energy booster bottles the player can make//
 printf ("How many bottles do you want to make? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > nEnergyBCount || nQuantity < 0) //Makes sure the player entered a valid number//
 {
 if (nEnergyBCount < nQuantity)
 printf ("You don't have enough ingredients to make that amount. ");

 if (nQuantity < 0)
 printf ("Enter a valid amount. ");

 scanf ("%d", &nQuantity);
 }

 //Adding new bottles of Energy Booster and subtracting the ingredients//
 *nEnergyB += nQuantity;
 *nLemon -= nQuantity;
 *nRoseM -= nQuantity;
 *nMint -= nQuantity;

 //Charges the player if he makes diffuser oils and doesn't execute if the player chose to not make any diffuser oil//
 if (nQuantity > 0)
 *nCash -= nCharge;
 }
 }

 if (nChoice == 3) //Player chooses to make bottles of Calming//
 {
 // Getting max bottles of Calming the player can make //
 if (*nLemon <= *nRoseM / 2 && *nLemon <= *nLavender / 3)
 nCalmingCount = *nLemon;

 if (*nRoseM / 2 <= *nLemon && *nRoseM / 2 <= *nLavender / 3)
 nCalmingCount = *nRoseM / 2;

 if (*nLavender / 3 <= *nRoseM / 2 && *nLavender / 3 <= *nLemon)
 nCalmingCount = *nLavender / 3;

 // Check if the player has enough money to pay the charge//
 if (*nCash < nCharge)
 {
 printf ("\nYou don't have enough money to pay the charge. Press 1 to exit. ");

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
 else
 {
 printf ("\nYou can make %d bottles of Calming.\n", nCalmingCount); // The max amount of Calming bottles the player can make//
 printf ("How many bottles do you want to make? ");
 scanf ("%d", &nQuantity);

 while (nQuantity > nCalmingCount || nQuantity < 0) //Makes sure the player entered a valid number//
 {
 if (nCalmingCount < nQuantity)
 printf ("You don't have enough ingredients to make that amount. ");

 if (nQuantity < 0)
 printf ("Enter a valid amount. ");

 scanf ("%d", &nQuantity);
 }

 //Adding new bottles of Energy Booster and subtracting the ingredients//
 *nCalming += nQuantity;
 *nLemon -= nQuantity;
 *nRoseM -= nQuantity * 2;
 *nLavender -= nQuantity * 3;

 //Charges the player if he makes diffuser oils and doesn't execute if the player chose to not make any diffuser oil//
 if (nQuantity > 0)
 *nCash -= nCharge;
 }
 }

 if (nChoice == 0)
 {
 printf ("\nYou chose not to make anything. Press 1 to exit. "); //The player entered 0 as nChoice//

 while (nExit != 1)
 {
 scanf ("%d", &nExit);
 }
 }
}
void choosePayDebt (int *nCash, int *nDebt)
{
 /*
 Description: The function updates the value of nDebt and nCash when the
player chooses to pay his debts.

 Parameters:
 int *nCash - To update the amount of cash after paying debts.
 int *nDebt - To update the amount of debt left after paying debts.

 Return value: None
 */

 int nPayment;
 int nExit = 0;

 printf ("You decided to visit the loan shark.");

 if (*nDebt > 0)
 {
 printf ("\nHow much do you want to pay? ");
 scanf ("%d", &nPayment);

 while (nPayment < 0 || nPayment > *nCash || nPayment > *nDebt) //Makes sure the player entered a valid amount//
 {
 if (nPayment < 0)
 printf ("Enter a valid number. ");

 if (nPayment > *nCash)
 printf ("You don't have enough cash. Enter a value you can pay. ");

 if (nPayment > *nDebt)
 printf ("You only have to pay $%d. ", *nDebt); //Prevents overpaying//

 scanf ("%d", &nPayment);
 }

 *nCash -= nPayment; //Updates the amount of cash after paying debts//
 *nDebt -= nPayment; //Updates the amount of remaining debt after paying debts//
 }

 else
 {
 printf ("\nYou currently have no debts. Press 1 to exit. "); // This message shows if nDebt = 0 or the player currently has no debts//

 while (nExit != 1) //Exit the screen//
 {
 scanf ("%d", &nExit);
 }
 }
}
void chooseLoan (int* nDebt, int* nCash)
{
 /*
 Description: The function updates the value of nDebt and nCash when the
player chooses to loan.
 Parameters:
 int* nDebt - To update the debt of the player
 int* nCash - To add cash after loaning cash

 Return value: None
 */

 int nNewLoan;

 printf ("\nYou decided to visit the loan shark.");
 printf ("\nHow much do you want to loan? ");
 scanf ("%d", &nNewLoan);

 while (nNewLoan < 0) //To make sure the entered number is valid //
 {
 printf ("Enter a valid number. ");
 scanf ("%d", &nNewLoan);
 }

 *nDebt += nNewLoan; //Adds debt and updates the amount of debt after loaning//
 *nCash += nNewLoan; //Adds and updates the amount of cash after loaning//
}
void chooseTravel (int* nLocation, int* nDay, int *nExitChoiceMenu)
{
 /*
 Description: This function updates the location if the player chooses to
travel and ends the day.

 Parameters:
 int* nLocation - To update the location if the player decides to travel
 int* nDay - To end the day if the player decides to travel.
 int *nExitChoiceMenu - To exit choice menu loop when ending the day

 Return value: None
 */

 int nChoice;
 int nExit = 0;

 printf ("\nWhere do you want to go?\n");
 printf ("(1) Manila, (2) Makati, (3) Alabang, (4) Quezon City\n");
 scanf ("%d", &nChoice);

 while (nChoice <= 0 || nChoice > 4)
 scanf ("%d", &nChoice);

 if (nChoice != *nLocation) //The number entered is not the same as the current location, the player will travel and end the day//
 {
 *nLocation = nChoice;
 *nDay += 1;
 *nExitChoiceMenu = 1;
 }

 else
 {
 printf ("\nYou chose to not travel. Press 1 to Exit. "); //The number entered is the same as the current location, the player will stay//

 while (nExit != 1)
 scanf ("%d", &nExit);
 }
}
void displayEndGame (int nCash, int nDebt, int nLemon, int nRoseM, int nMint, int
nLavender, int nClearM, int nEnergyB, int nCalming)
{
 /*
 Description: Displays the end screen and the player's summary.
 Parameters:
 int nCash - To display the amount of cash the player gathered.
 int nDebt - To display the amount of debt the player has left.
 int nLemon - To display the amount of lemon drops the player has.
 int nRoseM - To display the amount of rosemary drops the player has.
 int nMint - To display the amount of mint drops the player has.
 int nLavender - To display the amount of lavender drops the player has.
 int nClearM - To display the number of Clear Minds bottles the player has.
 int nEnergyB - To display the number of Energy Booster bottles the player
has.
 int nCalming - To display the number of Energy Booster bottles the player
has.

 Return value: void
 */

 int nChoice;

 system ("cls");

 //Display the Score table//
 printf ("\n%s%s%s%s%s\n", "==========", "==========", "==========",
"==========", "==========");
 printf ("%32s", "END GAME SCORE:");
 printf ("\n%s%s%s%s%s\n", "==========", "==========", "==========",
"==========", "==========");

 printf ("%-14s$%d\n","Cash: ", nCash);
 printf ("%-14s$%d\n","Debt: ", nDebt);
 printf ("%s$%d\n","Final amount: ", nCash - nDebt);
 printf ("\n%s%s%s%s%s\n", "==========", "==========", "==========",
"==========", "==========");

 printf ("%37s\n\n", "Remaining Essential Oils:");
 printf ("%17s%9d%16s\n","Lemon", nLemon, " drops");
 printf ("%17s%9d%16s\n","Rosemary", nRoseM, " drops");
 printf ("%17s%9d%16s\n","Mint", nMint, " drops");
 printf ("%17s%9d%16s\n","Lavender", nLavender, " drops");
 printf ("\n%s%s%s%s%s\n", "==========", "==========", "==========",
"==========", "==========");

 printf ("%37s\n\n", "Remaining Diffuser Oils:");
 printf ("%17s%9d%16s\n","Clear Minds", nClearM, " btls");
 printf ("%17s%9d%16s\n","Energy Booster", nEnergyB, " btls");
 printf ("%17s%9d%16s\n","Calming", nCalming, " btls");
 printf ("\n%s%s%s%s%s\n\n", "==========", "==========", "==========",
"==========", "==========");

 //Press 1 to exit the screen//
 printf ("Press 1 to continue. ");
 scanf ("%d", &nChoice);

 while (nChoice != 1)
 scanf ("%d", &nChoice);
}
int main ()
{
 // Important default variables//
 int nStart = 0;
 int nEnd;
 int nChoice;
 int nExitChoiceMenu;

 //Player details//
 int nDay, nCash, nDebt;
 int nLocation;
 char* cLocation;

 // Locations //
 char* cL1 = "Manila";
 char* cL2 = "Makati";
 char* cL3 = "Alabang";
 char* cL4 = "Quezon City";

 // Inventory Variables //
 int nLemon, nAveLemon;
 int nRoseM, nAveRoseM;
 int nMint, nAveMint;
 int nLavender, nAveLavender;
 int nClearM, nAveClearM;
 int nEnergyB, nAveEnergyB;
 int nCalming, nAveCalming;

 // The prices of oils or expenses//
 int nLemonPrice;
 int nRoseMPrice;
 int nMintPrice;
 int nLavenderPrice;
 int nClearMPrice;
 int nEnergyBPrice;
 int nCalmingPrice;
 int nCharge;

 // Acquired bottles of essential oil needed to calculate average cost per drop//
 int nNewLemon;
 int nNewRoseM;
 int nNewMint;
 int nNewLavender;

 //Game loop starts//
 while (nStart != 2)
 {
 // Start Display //
 nStart = displayStart ();

 // Game Begins //
 if (nStart == 1)
 {
 //Setting default player details variables//
 nDay = 1;
 nCash = 1500;
 nDebt = 4000;
 cLocation = cL1;
 nLocation = 1;
 nEnd = 0;

 //Setting default player inventory variables//
 nLemon = 0, nAveLemon = 0;
 nRoseM = 0, nAveRoseM = 0;
 nMint = 0, nAveMint = 0;
 nLavender = 0, nAveLavender = 0;
 nClearM = 0, nAveClearM = 0;
 nEnergyB = 0, nAveEnergyB = 0;
 nCalming = 0, nAveCalming = 0;

 //Setting default diffuser and essential oil Prices//
 nLemonPrice = 0;
 nRoseMPrice = 0;
 nMintPrice = 0;
 nLavenderPrice = 0;
 nClearMPrice = 0;
 nEnergyBPrice = 0;
 nCalmingPrice = 0;

 //Loops until day 15 has ended or if player decides to quit game//
 while (nDay <= 15 && nEnd == 0)
 {
 system ("cls");

 // Getting player's current location //

 if (nLocation == 1)
 cLocation = cL1;

 if (nLocation == 2)
 cLocation = cL2;

 if (nLocation == 3)
 cLocation = cL3;

 if (nLocation == 4)
 cLocation = cL4;

 //~~~~~~~~BACKGROUND GAME FORMULAS~~~~~~~~//

 // Resetting the variables to get average price per drop//
 nNewLemon = 0;
 nNewRoseM = 0;
 nNewMint = 0;
 nNewLavender = 0;

 //Computes the debt
 nDebt = computeDebt (nDebt, nDay);

 //Generates the charge to make diffuser oils in the location//
 generateCityCharge (nLocation, &nCharge);

 //Generates the random prices of essential oils//
 generateEssOilPrice (&nLemonPrice, &nRoseMPrice, &nMintPrice,
&nLavenderPrice);

 //Generates the prices of diffuser oils based on the prices of essential oils//
 computeDiffOilPrice (&nClearMPrice, &nEnergyBPrice, &nCalmingPrice,
nLemonPrice, nRoseMPrice, nMintPrice, nLavenderPrice);

 //Computes the average essential oil prices based on the current inventory and prices//
 computeAverageEssOil (nLemon, nRoseM, nMint, nLavender,
nLemonPrice, nRoseMPrice, nMintPrice, nLavenderPrice, &nAveLemon, &nAveRoseM,
&nAveMint, &nAveLavender, &nNewLemon, &nNewRoseM, &nNewMint, &nNewLavender);

 //Computes the average diffuser oil prices based on the current inventory and prices//
 computeAverageDiffOil (nClearM, nEnergyB, nCalming, &nAveClearM,
&nAveEnergyB, &nAveCalming, nAveLemon, nAveRoseM, nAveMint, nAveLavender, nCharge);


 //~~~~~~~~DISPLAYS ON SCREEN~~~~~~~~//

 //Generate Freebies at start of day//

 generateFreebieChance (&nLemon, &nRoseM, &nMint, &nLavender,
&nClearM, &nEnergyB, &nCalming);

 system ("cls");

 //Display Player details and inventory//
 displayDetails (nDay, nCash, nDebt, cLocation, nCharge);

 displayInventory (nLemon, nRoseM, nMint, nLavender, nClearM,
nEnergyB, nCalming, nLemonPrice, nRoseMPrice, nMintPrice, nLavenderPrice,
nClearMPrice, nEnergyBPrice, nCalmingPrice, nAveLemon, nAveRoseM, nAveMint,
nAveLavender, nAveClearM, nAveEnergyB, nAveCalming);


 // Player will choose what actions to do //
 nChoice = 0;
 nExitChoiceMenu = 0;
 //DISPLAY CHOICE MENU//
 while (nChoice != 7 && nExitChoiceMenu == 0)
 {
 if (nDay == 15) //Displays when the player is on the last day of the game//
 {
 printf ("\nWould you like to (1) BUY, (2) SELL, (3) MAKE, (4) PAY DEBT, (5) LOAN, or (7) END GAME? ");
 scanf ("%d", &nChoice);
 }
 else //Default display of options//
 {
 printf ("\nWould you like to (1) BUY, (2) SELL, (3) MAKE, (4) PAY DEBT, (5) LOAN, (6) TRAVEL or (7) QUIT GAME? ");
 scanf ("%d", &nChoice);
 }

 if (nChoice == 1) //Player chooses to buy//
 {
 chooseBuy (nLemonPrice, nLavenderPrice, nRoseMPrice,
nMintPrice, &nLemon, &nLavender, &nRoseM, &nMint, &nCash, &nNewLemon, &nNewRoseM,
&nNewMint, &nNewLavender);

 system ("cls");

 // Call again to update details and inventory//
 displayDetails (nDay, nCash, nDebt, cLocation, nCharge);

 computeAverageEssOil (nLemon, nRoseM, nMint, nLavender,
nLemonPrice, nRoseMPrice, nMintPrice, nLavenderPrice, &nAveLemon, &nAveRoseM,
&nAveMint, &nAveLavender, &nNewLemon, &nNewRoseM, &nNewMint, &nNewLavender);

 displayInventory (nLemon, nRoseM, nMint, nLavender,
nClearM, nEnergyB, nCalming, nLemonPrice, nRoseMPrice, nMintPrice, nLavenderPrice,
nClearMPrice, nEnergyBPrice, nCalmingPrice, nAveLemon, nAveRoseM, nAveMint,
nAveLavender, nAveClearM, nAveEnergyB, nAveCalming);
 }
 if (nChoice == 2) //Player chooses to sell//
 {
 chooseSell (nLemonPrice, nLavenderPrice, nRoseMPrice,
nMintPrice, nEnergyBPrice, nCalmingPrice, nClearMPrice, &nLemon, &nLavender,
&nRoseM, &nMint, &nEnergyB, &nClearM, &nCalming, &nCash);

 system ("cls");

 // Call again to update details and inventory//
 displayDetails (nDay, nCash, nDebt, cLocation, nCharge);

 displayInventory (nLemon, nRoseM, nMint, nLavender,
nClearM, nEnergyB, nCalming, nLemonPrice, nRoseMPrice, nMintPrice, nLavenderPrice,
nClearMPrice, nEnergyBPrice, nCalmingPrice, nAveLemon, nAveRoseM, nAveMint,
nAveLavender, nAveClearM, nAveEnergyB, nAveCalming);
 }

 if (nChoice == 3) //Player chooses to make diffuser oils//
 {
 chooseMakeDiffOil (&nLemon, &nRoseM, &nMint, &nLavender,
&nCalming, &nEnergyB, &nClearM, nCharge, &nCash);

 system ("cls");

 // Call again to update details and inventory//
 displayDetails (nDay, nCash, nDebt, cLocation, nCharge);

 displayInventory (nLemon, nRoseM, nMint, nLavender,
nClearM, nEnergyB, nCalming, nLemonPrice, nRoseMPrice, nMintPrice, nLavenderPrice,
nClearMPrice, nEnergyBPrice, nCalmingPrice, nAveLemon, nAveRoseM, nAveMint,
nAveLavender, nAveClearM, nAveEnergyB, nAveCalming);
 }

 if (nChoice == 4) //Player chooses to pay debts//
 {
 choosePayDebt (&nCash, &nDebt);

 system ("cls");

 // Call again to update details and inventory//
 displayDetails (nDay, nCash, nDebt, cLocation, nCharge);

 displayInventory (nLemon, nRoseM, nMint, nLavender,
nClearM, nEnergyB, nCalming, nLemonPrice, nRoseMPrice, nMintPrice, nLavenderPrice,
nClearMPrice, nEnergyBPrice, nCalmingPrice, nAveLemon, nAveRoseM, nAveMint,
nAveLavender, nAveClearM, nAveEnergyB, nAveCalming);
 }

 if (nChoice == 5) //Player chooses to loan //
 {
 chooseLoan (&nDebt, &nCash);

 system ("clear");

 // Call again to update details and inventory //
 displayDetails (nDay, nCash, nDebt, cLocation, nCharge);

 displayInventory (nLemon, nRoseM, nMint, nLavender,
nClearM, nEnergyB, nCalming, nLemonPrice, nRoseMPrice, nMintPrice, nLavenderPrice,
nClearMPrice, nEnergyBPrice, nCalmingPrice, nAveLemon, nAveRoseM, nAveMint,
nAveLavender, nAveClearM, nAveEnergyB, nAveCalming);
 }

 if (nChoice == 6) //Player chooses to travel //
 {
 chooseTravel (&nLocation, &nDay, &nExitChoiceMenu);

 system ("cls");

 // Call again just in case player chose not to travel//
 displayDetails (nDay, nCash, nDebt, cLocation, nCharge);

 displayInventory (nLemon, nRoseM, nMint, nLavender,
nClearM, nEnergyB, nCalming, nLemonPrice, nRoseMPrice, nMintPrice, nLavenderPrice,
nClearMPrice, nEnergyBPrice, nCalmingPrice, nAveLemon, nAveRoseM, nAveMint,
nAveLavender, nAveClearM, nAveEnergyB, nAveCalming);
 }
 }

 if (nChoice == 7) //Player chooses to end game //
 nEnd = 1;
 }

 //~~~~~~~~DISPLAY END GAME SUMMARY~~~~~~~~//
 displayEndGame (nCash, nDebt, nLemon, nRoseM, nMint, nLavender,
nClearM, nEnergyB, nCalming);

 system ("cls");
 }
 }

 if (nStart == 2) //Player chooses to end the program//
 printf ("\nThank You For Playing!");

 return 0;
}