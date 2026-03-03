#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void)
{
   // Ints for later required math to display stats
   int numLevel, heroicInsp, numStr, numDex, numCon, numInt, numWis, numCha;

   // first 20 string input info
   string line, name, background, charClass, species, subclass, level, XP, AC, CurrentHP, TempHP, MaxHP, Str, Dex, Con, Int, Wis, Cha, Size, Speed, HitDice, SpentHitDice;
   // input line reading help vars
   int Armors = 0;
   int Weaps = 0;
   int Skills = 0;
   int Tools = 0;
   int EqpDsc = 0;
   int totalEqps = 0;
   int CFeats = 0;
   int NextCFeat = 0; // 0 for no, 1 for yes
   int SFeats= 0;
   int NextSFeat = 0; // 0 for no, 1 for yes
   int Feats = 0;
   int NextFeat = 0; // 0 for no, 1 for yes
   int shield = 0;
   int lineCount = 0;

   // variables for the 
   vector<int> ArmorList = {0,0,0,0}; // 0 for no, 1 for yes {0=Shield, 1=Light, 2=Medium, 3=Heavy}
   vector<string> WeaponList;
   vector<int> SkillList = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
   // 0 for no, 1 for yes 
   // {
   //   0=Acrobatics, 1=AnimalHandling, 2=Arcana, 3=Athletics, 4=Deception, 5=History
   //   6=Insight, 7=Intimidation, 8=Investigation, 9=Medicine, 10=Nature, 11=Perception
   //   12=Performance, 13=Persuasion, 14=Religion, 15=SleightOfHand, 16=Stealth, 17=Survival,
   //   18=StrSave, 19=DexSave, 20=ConSave, 21=IntSave, 22=WisSave, 23=ChaSave
   // }
   vector<string> ToolList;
   vector<vector<string>> EquippedList;
   vector<string> CFeatList;
   vector<string> SFeatList;
   vector<string> FeatList;

   // variables for individual longer entries
   vector<string> CurrEqp;
   
   while (getline(cin, line) && !line.empty())
   {
        // increment lineCount by one
        lineCount = lineCount+1;

        if (lineCount <= 22)
        { 
                switch (lineCount) {
                // 1st line is the name
                case 1:
                        name = line;
                        break;
                //2nd line is background
                case 2:
                        background = line;
                        break;
                //3rd line is species
                case 3:
                        species = line;
                        break;
                //4th line is character class
                case 4:
                        charClass= line;
                        break;
                //5th line is subclass
                case 5:
                        subclass = line;
                        break;
                //6th line is level
                case 6:
                        numLevel = stoi(line);
                        level = line;
                        break;
                //7th line is XP
                case 7:
                        XP = line;
                        break;
                //8th line is AC
                case 8:
                        AC = line;
                        break;
                //9th line is Current HP
                case 9:
                        CurrentHP = line;
                        break;
                //10th line is Temp HP
                case 10:
                        TempHP = line;
                        break;
                //11th line is Max HP
                case 11:
                        MaxHP = line;
                        break;
                //12th line is Heroic Inspiration
                case 12:
                        heroicInsp = stoi(line);
                        break;
                //13th line is Strength Score
                case 13:
                        numStr = stoi(line);
                        if(numStr > 0 && numStr < 31)
                        {
                                Str = line;
                        }
                        else
                        {
                                cerr << "Need a number between 1-30 for Stength Val!" << endl;
                                return 0;
                        }
                        break;
                //14th line is Dexterity Score
                case 14:
                        numDex = stoi(line);
                        if(numDex > 0 && numDex < 31)
                        {
                                Dex = line;
                        }
                        else
                        {
                                cerr << "Need a number between 1-30 for Dexterity Val!" << endl;
                                return 0;
                        }
                        break;
                //15th line is Constitution Score
                case 15:
                        numCon = stoi(line);
                        if(numCon > 0 && numCon < 31)
                        {
                                Con = line;
                        }
                        else
                        {
                                cerr << "Need a number between 1-30 for Constitution Val!" << endl;
                                return 0;
                        }
                        break;
                //16th line is Intelligence Score
                case 16:
                        numInt = stoi(line);
                        if(numInt > 0 && numInt < 31)
                        {
                                Int = line;
                        }
                        else
                        {
                                cerr << "Need a number between 1-30 for Intelligence Val!" << endl;
                                return 0;
                        }
                        break;
                //17th line is Wisdom Score
                case 17:
                        numWis = stoi(line);
                        if(numWis > 0 && numWis < 31)
                        {
                                Wis = line;
                        }
                        else
                        {
                                cerr << "Need a number between 1-30 for Wisdom Val!" << endl;
                                return 0;
                        }
                        break;
                //18th line is Charisma Score
                case 18:
                        numCha = stoi(line);
                        if(numCha > 0 && numCha < 31)
                        {
                                Cha = line;
                        }
                        else
                        {
                                cerr << "Need a number between 1-30 for Charisma Val!" << endl;
                        }
                        break;
                //19th line is the Size
                case 19:
                        if (line!= "M" && line!= "S" && line!= "L")
                        {
                                cerr << "Incorrect size modifier! Need either L for large, M for medium or S for small!" << endl;
                        }
                        else
                        {
                                Size = line;
                        }
                        break;
                //20th line is the Speed
                case 20:
                        Speed = line;
                        break;
                //21st line is the Hit dice
                case 21:
                        HitDice = line;
                        break;
                //22nd line is the spent hit dice
                case 22:
                        SpentHitDice = line;
                        break;
                default:

                        break;
                }
        }
        else if(lineCount>22) // past the first 22 lines, so long descripts from here
        {
                // if in a long description for something, make the longDescription variable 1.
                // These if statements will catch the start of longer descriptions based on the start word.
                if (line == "ARMORS" && Armors==0) {Armors=1; continue;}
                else if (line == "WEAPONS" && Weaps==0) {Weaps=1; Armors = 5; continue;}
                else if (line == "SKILLS" && Skills==0) {Skills=1; Weaps = 11; continue;}
                else if (line == "TOOLS" && Tools==0) {Tools=1; Skills = 24; continue;}
                else if (line == "EQUIPPED" && totalEqps < 6) 
                {
                        // set it to read the first next line of the current description, and clear the current equipment vector
                        Tools = 6;
                        EqpDsc=1;
                        CurrEqp = {"", "", "", ""};
                        continue;
                }
                else if (line == "CFEAT" && CFeats <= 10) {NextCFeat=1; totalEqps = 6; continue;}
                else if (line == "SFEAT" && SFeats <= 10) {NextSFeat=1; CFeats = 6; continue;}
                else if (line == "FEAT" && Feats <= 10) {NextFeat=1; SFeats = 6; continue;}

                // any line of the armor proficiencies:
                if(Armors>=1 && Armors != 5)
                {
                        // again, the index for each is 1 for yes {0=Shield, 1=Light, 2=Medium, 3=Heavy}
                        if(line == "Shield") {ArmorList[0] = 1;}
                        else if(line == "Light"){ArmorList[1] = 1;}
                        else if(line == "Medium"){ArmorList[2] = 1;}
                        else if(line == "Heavy"){ArmorList[3] = 1;}
                        Armors = Armors+1;
                }

                // any line of the weapon proficiencies:
                if(Weaps>=1 && Weaps != 11)
                {

                        WeaponList.push_back(line);
                        Weaps = Weaps+1;
                }

                // any line of the skill proficiencies:
                if(Skills>=1 && Skills != 24)
                {
                        // 0 for no, 1 for yes 
                        // {
                        //   0=Acrobatics, 1=AnimalHandling, 2=Arcana, 3=Athletics, 4=Deception, 5=History
                        //   6=Insight, 7=Intimidation, 8=Investigation, 9=Medicine, 10=Nature, 11=Perception
                        //   12=Performance, 13=Persuasion, 14=Religion, 15=SleightOfHand, 16=Stealth, 17=Survival,
                        //   18=StrSave, 19=DexSave, 20=ConSave, 21=IntSave, 22=WisSave, 23=ChaSave
                        // }
                        if(line == "Acrobatics") {SkillList[0] = 1;}
                        else if(line == "AnimalHandling"){SkillList[1] = 1;}
                        else if(line == "Arcana"){SkillList[2] = 1;}
                        else if(line == "Athletics"){SkillList[3] = 1;}
                        else if(line == "Deception"){SkillList[4] = 1;}
                        else if(line == "History"){SkillList[5] = 1;}
                        else if(line == "Insight"){SkillList[6] = 1;}
                        else if(line == "Intimidation"){SkillList[7] = 1;}
                        else if(line == "Investigation"){SkillList[8] = 1;}
                        else if(line == "Medicine"){SkillList[9] = 1;}
                        else if(line == "Nature"){SkillList[10] = 1;}
                        else if(line == "Perception"){SkillList[11] = 1;}
                        else if(line == "Performance"){SkillList[12] = 1;}
                        else if(line == "Persuasion"){SkillList[13] = 1;}
                        else if(line == "Religion"){SkillList[14] = 1;}
                        else if(line == "SleightOfHand"){SkillList[15] = 1;}
                        else if(line == "Stealth"){SkillList[16] = 1;}
                        else if(line == "Survival"){SkillList[17] = 1;}
                        else if(line == "StrSave"){SkillList[18] = 1;}
                        else if(line == "DexSave"){SkillList[19] = 1;}
                        else if(line == "ConSave"){SkillList[20] = 1;}
                        else if(line == "IntSave"){SkillList[21] = 1;}
                        else if(line == "WisSave"){SkillList[22] = 1;}
                        else if(line == "ChaSave"){SkillList[23] = 1;}
                        Skills = Skills+1;
                }

                // any line of the tool proficiencies:
                if(Tools>=1 && Tools != 6)
                {

                        ToolList.push_back(line);
                        Tools = Tools+1;
                }

                // if its any line of the equipment description and its not a shield.
                if(EqpDsc>=1 && totalEqps != 6)
                {
                        // first line of eqp description, so the name of the thing
                        if (EqpDsc == 1)
                        {
                                // if its a shield
                                if (line=="Shield")
                                {       
                                        // and we dont have a shield already
                                        if (shield == 0)
                                        {
                                                shield=1;
                                                EqpDsc=1;
                                                continue;
                                        }
                                        else if (shield!=0)
                                        {
                                                cerr << "Read more than one shield!" << endl;
                                                EqpDsc=1;
                                                continue; 
                                        }
                                } 
                                else
                                {
                                        // limit name to 15 chars
                                        if(line.length() <= 15)
                                        {
                                                CurrEqp[0] = line;
                                                EqpDsc = 2;
                                                continue;
                                        }
                                        else
                                        {
                                                cerr << "Equipped item: " << line << " name too long! Please abbreviate!" << endl;
                                                EqpDsc=1;
                                                continue; 
                                        }
                                }
                        }
                        else if (EqpDsc == 2) // 2nd line, so the attack bonus/save DC
                        {
                               // limit attack bonus/save DC to 7 chars
                               if(line.length() <= 7)
                               {
                                       CurrEqp[1] = line;
                                       EqpDsc = 3;
                                       continue;
                               }
                               else
                               {
                                       cerr << "Equipped item: " << line << " attack bonus/save DC too long! Please abbreviate!" << endl;
                                       EqpDsc=1;
                                       continue; 
                               } 
                        }
                        else if (EqpDsc == 3) // 3rd line, so the damage, damage type, and bonus.
                        {
                               // limit damage, damage type, and bonus to 12 chars
                               if(line.length() <= 12)
                               {
                                       CurrEqp[2] = line;
                                       EqpDsc = 4;
                                       continue;
                               }
                               else
                               {
                                       cerr << "Equipped item: " << line << " damage, damage type, and bonus too long! Please abbreviate!" << endl;
                                       EqpDsc=0;
                                       continue;  
                               } 
                        }
                        else if (EqpDsc == 4) // 3rd line, so the notes.
                        {
                               // limit notes to 20 chars
                               if(line.length() <= 20)
                               {
                                        CurrEqp[3] = line;
                                        EqpDsc = 1;

                                        // now the item is done, so we push it back onto the equipped list
                                        EquippedList.push_back(CurrEqp);
                                        totalEqps = totalEqps + 1;
                                        continue;
                               }
                               else
                               {
                                        cerr << "Equipped item: " << line << " notes too long! Please abbreviate!" << endl;
                                        EqpDsc=1;
                                        continue; 
                               } 
                        }              
                }

                // any line of the class features:
                if(NextCFeat==1 && CFeats != 6)
                {
                        CFeatList.push_back(line);
                        CFeats = CFeats+1;
                        NextCFeat=0;
                }

                // any line of the species features:
                if(NextSFeat==1 && SFeats != 6)
                {
                        SFeatList.push_back(line);
                        SFeats = SFeats+1;
                        NextSFeat=0;
                }

                // any line of the feats:
                if(NextFeat==1 && Feats != 6)
                {
                        FeatList.push_back(line);
                        Feats = Feats+1;
                        NextFeat=0;
                }
        }
   }

        // -- GRAPH/Character Sheet GENERATION --

        // make the graph
        int xmax, ymax, xmin, ymin;
        xmin = 0;
        ymin = 0;
        ymax = 100;
        xmax = 100;
        cout << "newgraph" << endl;
        cout << "xaxis min " << xmin << " max " << xmax << " nodraw" << endl;
        cout << "yaxis min " << ymin << " max " << ymax << " nodraw" << endl;

        // print out name, background, class, species, and subclass box.
        cout << "newcurve eps symbols/name_box.ps marksize 125 100 pts -105 383" << endl;

        // print out Level/XP and AC boxes
        cout << "newcurve eps symbols/level.ps marksize 50 50 pts -31 383" << endl;
        cout << "newcurve eps symbols/ac.ps marksize 50 50 pts 0 383" << endl;
        // shield indicator (if equipped)
        if(shield==1)
        {
                cout << "newcurve marktype circle marksize 4 4 fill 0.5 pts 0 365" << endl;
        }

        // print out boxes for curr, max, temp HP, plus total and spent HitDice
        cout << "newcurve eps symbols/health.ps marksize 50 50 pts 47 383" << endl;
        cout << "newcurve eps symbols/hitdice.ps marksize 50 50 pts 91 383" << endl;

        // print out box for proficiency bonus and heroic inspiration
        cout << "newcurve eps symbols/prof_bonus.ps marksize 50 50 pts -140 332" << endl;
        cout << "newcurve eps symbols/heroic_ins.ps marksize 50 50 pts -85 332" << endl;

        // print out initiative, speed, size, and passive perception boxes
        cout << "newcurve eps symbols/initiative.ps marksize 50 50 pts -35 332" << endl;
        cout << "newcurve eps symbols/speed.ps marksize 50 50 pts 5 332" << endl;
        cout << "newcurve eps symbols/size.ps marksize 50 50 pts 45 332" << endl;
        cout << "newcurve eps symbols/pass_perc.ps marksize 50 50 pts 85 332" << endl;

        // print out boxes for  Str, Dex, Con, Int, Wis, and Cha ability mods and saving throws
        cout << "newcurve eps symbols/ability_mod.ps marksize 50 50 pts -140 293" << endl;
        cout << "newcurve eps symbols/ability_mod.ps marksize 50 50 pts -85 293" << endl;
        cout << "newcurve eps symbols/ability_mod.ps marksize 50 50 pts -140 242" << endl;
        cout << "newcurve eps symbols/ability_mod.ps marksize 50 50 pts -85 242" << endl;
        cout << "newcurve eps symbols/ability_mod.ps marksize 50 50 pts -140 191" << endl;
        cout << "newcurve eps symbols/ability_mod.ps marksize 50 50 pts -85 191" << endl;

        // print out box for skill bonuses and weap, armor, and tool proficiencies.
        cout << "newcurve eps symbols/skills.ps marksize 105.5 105.5 pts -112.5 129" << endl;
        cout << "newcurve eps symbols/weaps_tools.ps marksize 105.5 105.5 pts -112.5 55" << endl;

        // print out the equpped table
        cout << "newcurve eps symbols/equipped.ps marksize 160 160 pts 24 281" << endl;

        //print out all feat boxes
        cout << "newcurve eps symbols/feat.ps marksize 160 160 pts 24 198" << endl;
        cout << "newcurve eps symbols/feat.ps marksize 160 160 pts 24 126" << endl;
        cout << "newcurve eps symbols/feat.ps marksize 160 160 pts 24 54" << endl;

        // put name on sheet
        printf("newstring font Helvetica fontsize %d x %d y %d hjl vjc :\n",
                12,
                -158,
                396);
        printf("%s\n", name.c_str());
        // put name indicator on sheet
        string nameInd = "CHARACTER NAME";
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                6,
                -145,
                390);
        printf("%s\n", nameInd.c_str());

        // put background on sheet
        printf("newstring font Helvetica fontsize %d x %d y %d hjl vjc :\n",
                10,
                -158,
                383);
        printf("%s\n", background.c_str());
        // put background indicator on sheet
        string backgroundInd = "BACKGROUND";
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                6,
                -147,
                378);
        printf("%s\n", backgroundInd.c_str());

        // put character class on sheet
        printf("newstring font Helvetica fontsize %d x %d y %d hjl vjc :\n",
                10,
                -102,
                383);
        printf("%s\n", charClass.c_str());
        // put character class indicator on sheet
        string charClassInd = "CLASS";
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                6,
                -98,
                378);
        printf("%s\n", charClassInd.c_str());

        // put species on sheet
        printf("newstring font Helvetica fontsize %d x %d y %d hjl vjc :\n",
                10,
                -158,
                371);
        printf("%s\n", species.c_str());
        // put species indicator on sheet
        string speciesInd = "SPECIES";
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                6,
                -152,
                366);
        printf("%s\n", speciesInd.c_str());

        // put character subclass on sheet
        printf("newstring font Helvetica fontsize %d x %d y %d hjl vjc :\n",
                10,
                -102,
                371);
        printf("%s\n", subclass.c_str());
        // put character subclass indicator on sheet
        string subclassInd = "SUBCLASS";
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                6,
                -96,
                366);
        printf("%s\n", subclassInd.c_str());
	

        // level
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                20,
                -31,
                388);
        printf("%s\n", level.c_str());
        // XP
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -31,
                372);
        printf("%s\n", XP.c_str());


        // Armor Class
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                24,
                0,
                382);
        printf("%s\n", AC.c_str());

        // current HP
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                22,
                32,
                372);
        printf("%s\n", CurrentHP.c_str());
        // temp HP
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                14,
                59,
                385);
        printf("%s\n", TempHP.c_str());
        // max HP
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                14,
                59,
                370);
        printf("%s\n", MaxHP.c_str());

        // spent Hit die
        string finalSpentHitDice = SpentHitDice + "" + HitDice;
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                14,
                90,
                385);
        printf("%s\n", finalSpentHitDice.c_str());
        // max hit die
        string maxHitDice = level + "" + HitDice;
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                14,
                90,
                370);
        printf("%s\n", maxHitDice.c_str());

        // proficiency bonus
        int pb = 2;
        if(numLevel > 1)
        {
                switch((numLevel-1)/4)
                {
                        case 1:
                                pb = 3;
                                break;
                        case 2:
                                pb = 4;
                                break;
                        case 3:
                                pb = 5;
                                break;
                        case 4:
                                pb = 6;
                                break;
                        default:
                                pb = 2;
                                break;
                }
        }
        string printPB = "+" + to_string(pb); 
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                18,
                -140,
                330);
        printf("%s\n", printPB.c_str());
        
        // heroic inspiration
        if(heroicInsp == 1)
        {
                heroicInsp = 0;
                printf("newcurve marktype circle marksize 4 4 fill 0.5 pts -85 327\n");
        }

        // speed
        string printSpeed = Speed + "ft."; 
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                18,
                5,
                330);
        printf("%s\n", printSpeed.c_str());

        // size
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                18,
                45,
                330);
        printf("%s\n", Size.c_str());


        // !----------------------START ability scores-----------------------------!

        // str score title
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                10,
                -140,
                313);
        printf("%s\n", "STRENGTH");

        // str score modifier
        int StrMod = (int)floor((numStr-10)/2.0f);
        string StrModPrint = to_string(StrMod);
        if(StrMod>0) {StrModPrint = "+" + to_string(StrMod);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                22,
                -150,
                298);
        printf("%s\n", StrModPrint.c_str());

        // str score itself
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                20,
                -128,
                298);
        printf("%s\n", Str.c_str());

        // str saving throw proficiency marker
        int strSavBonus = StrMod;
        if(SkillList[18]==1)
        {
                strSavBonus = strSavBonus + pb;
                SkillList[18] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -160 274.5\n");
        }

        // str saving throw bonus
        string printStrSavBonus = to_string(strSavBonus);
        if(strSavBonus > 0) {printStrSavBonus = "+" + to_string(strSavBonus);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                14,
                -151,
                275);
        printf("%s\n", printStrSavBonus.c_str());


        // dex score title
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                10,
                -140,
                262);
        printf("%s\n", "DEXTERITY");

        // dex score modifier
        int DexMod = (int)floor((numDex-10)/2.0f);
        string DexModPrint = to_string(DexMod);
        if(DexMod>0) {DexModPrint = "+" + to_string(DexMod);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                22,
                -150,
                247);
        printf("%s\n", DexModPrint.c_str());
        
        // dex score itself
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                20,
                -128,
                247);
        printf("%s\n", Dex.c_str());

        // dex saving throw proficiency marker
        int dexSavBonus = DexMod;
        if(SkillList[19]==1)
        {
                dexSavBonus = dexSavBonus + pb;
                SkillList[19] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -160 223.5\n");
        }

        // dex saving throw bonus
        string printDexSavBonus = to_string(dexSavBonus);
        if(dexSavBonus > 0) {printDexSavBonus = "+" + to_string(dexSavBonus);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                14,
                -151,
                224);
        printf("%s\n", printDexSavBonus.c_str());

        // initiative
        string printInitiative = to_string(DexMod);
        if(DexMod > 0) {printInitiative = "+" + to_string(DexMod);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                18,
                -35,
                330);
        printf("%s\n", printInitiative.c_str());



        // con score title
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                10,
                -140,
                211);
        printf("%s\n", "CONSTITUTION");

        // con score modifier
        int ConMod = (int)floor((numCon-10)/2.0f);
        string ConModPrint = to_string(ConMod);
        if(ConMod>0) {ConModPrint = "+" + to_string(ConMod);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                22,
                -150,
                196);
        printf("%s\n", ConModPrint.c_str());

        // con score itself
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                20,
                -128,
                196);
        printf("%s\n", Con.c_str());

        // con saving throw proficiency marker
        int conSavBonus = ConMod;
        if(SkillList[20]==1)
        {
                conSavBonus = conSavBonus + pb;
                SkillList[20] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -160 172.5\n");
        }

        // con saving throw bonus
        string printConSavBonus = to_string(conSavBonus);
        if(conSavBonus > 0) {printConSavBonus = "+" + to_string(conSavBonus);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                14,
                -151,
                173);
        printf("%s\n", printConSavBonus.c_str());





        // int score title
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                10,
                -85,
                313);
        printf("%s\n", "INTELLIGENCE");

        // int score modifier
        int IntMod = (int)floor((numInt-10)/2.0f);
        string IntModPrint = to_string(IntMod);
        if(IntMod>0) {IntModPrint = "+" + to_string(IntMod);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                22,
                -95,
                298);
        printf("%s\n", IntModPrint.c_str());

        // int score itself
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                20,
                -73,
                298);
        printf("%s\n", Int.c_str());

        // int saving throw proficiency marker
        int intSavBonus = IntMod;
        if(SkillList[21]==1)
        {
                intSavBonus = intSavBonus + pb;
                SkillList[21] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -105 274.5\n");
        }

        // int saving throw bonus
        string printIntSavBonus = to_string(intSavBonus);
        if(intSavBonus > 0) {printIntSavBonus = "+" + to_string(intSavBonus);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                14,
                -96,
                275);
        printf("%s\n", printIntSavBonus.c_str());



        // wis score title
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                10,
                -85,
                262);
        printf("%s\n", "WISDOM");

        // wis score modifier
        int WisMod = (int)floor((numWis-10)/2.0f);
        string WisModPrint = to_string(WisMod);
        if(WisMod>0) {WisModPrint = "+" + to_string(WisMod);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                22,
                -95,
                247);
        printf("%s\n", WisModPrint.c_str());

        // wis score itself
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                20,
                -73,
                247);
        printf("%s\n", Wis.c_str());
        
        // wis saving throw proficiency marker
        int wisSavBonus = WisMod;
        if(SkillList[22]==1)
        {
                wisSavBonus = wisSavBonus + pb;
                SkillList[22] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -105 223.5\n");
        }

        // wis saving throw bonus
        string printWisSavBonus = to_string(wisSavBonus);
        if(wisSavBonus > 0) {printWisSavBonus = "+" + to_string(wisSavBonus);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                14,
                -96,
                224);
        printf("%s\n", printWisSavBonus.c_str());






        // cha score title
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                10,
                -85,
                211);
        printf("%s\n", "CHARISMA");

        // cha score modifier
        int ChaMod = (int)floor((numCha-10)/2.0f);
        string ChaModPrint = to_string(ChaMod);
        if(ChaMod>0) {ChaModPrint = "+" + to_string(ChaMod);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                22,
                -95,
                196);
        printf("%s\n", ChaModPrint.c_str());

        // cha score itself
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                20,
                -73,
                196);
        printf("%s\n", Cha.c_str());

        // cha saving throw proficiency marker
        int chaSavBonus = ChaMod;
        if(SkillList[23]==1)
        {
                chaSavBonus = chaSavBonus + pb;
                SkillList[23] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -105 172.5\n");
        }

        // cha saving throw bonus
        string printChaSavBonus = to_string(chaSavBonus);
        if(chaSavBonus > 0) {printChaSavBonus = "+" + to_string(chaSavBonus);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                14,
                -96,
                173);
        printf("%s\n", printChaSavBonus.c_str());




        // !----------------------END ability scores-----------------------------!


        // ----------------------skill proficiency bonuses:---------------------
        


        // acrobatics: ---
        // - proficiency marker
        int acrobaticsProf= DexMod;
        if(SkillList[0]==1)
        {
                acrobaticsProf = acrobaticsProf + pb;
                SkillList[0] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -160 158.25\n");
        }
        // - bonus
        string printAcrobaticsProf = to_string(acrobaticsProf);
        if(acrobaticsProf > 0) {printAcrobaticsProf = "+" + to_string(acrobaticsProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -151,
                159);
        printf("%s\n", printAcrobaticsProf.c_str()); 




        // animal handling: ---
        // - proficiency marker
        int animProf= WisMod;
        if(SkillList[1]==1)
        {
                animProf = animProf + pb;
                SkillList[1] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -160 151\n");
        }
        // - bonus 
        string printAnimProf = to_string(animProf);
        if(animProf > 0) {printAnimProf = "+" + to_string(animProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -151,
                152);
        printf("%s\n", printAnimProf.c_str()); 




        // arcana: ---
        // - proficiency marker
        int arcanaProf= IntMod;
        if(SkillList[2]==1)
        {
                arcanaProf = arcanaProf + pb;
                SkillList[2] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -160 143.75\n");
        }
        // - bonus 
        string printArcanaProf = to_string(arcanaProf);
        if(arcanaProf > 0) {printArcanaProf = "+" + to_string(arcanaProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -151,
                145);
        printf("%s\n", printArcanaProf.c_str()); 
        



        // athletics: ---
        // - proficiency marker
        int athProf= StrMod;
        if(SkillList[3]==1)
        {
                athProf = athProf + pb;
                SkillList[3] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -160 136.5\n");
        }
        // - bonus 
        string printAthProf = to_string(athProf);
        if(athProf > 0) {printAthProf = "+" + to_string(athProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -151,
                138);
        printf("%s\n", printAthProf.c_str()); 




        // deception: ---
        // - proficiency marker
        int decProf= ChaMod;
        if(SkillList[4]==1)
        {
                decProf = decProf + pb;
                SkillList[4] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -160 129.25\n");
        }
        // - bonus 
        string printDecProf = to_string(decProf);
        if(decProf > 0) {printDecProf = "+" + to_string(decProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -151,
                131);
        printf("%s\n", printDecProf.c_str()); 




        // history: ---
        // - proficiency marker
        int histProf= IntMod;
        if(SkillList[5]==1)
        {
                histProf = histProf + pb;
                SkillList[5] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -160 122\n");
        }
        // - bonus 
        string printHistProf = to_string(histProf);
        if(histProf > 0) {printHistProf = "+" + to_string(histProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -151,
                124);
        printf("%s\n", printHistProf.c_str()); 
        



        // insight: ---
        // - proficiency marker
        int insiProf= WisMod;
        if(SkillList[6]==1)
        {
                insiProf = insiProf + pb;
                SkillList[6] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -160 114.75\n");
        }
        // - bonus 
        string printInsiProf = to_string(insiProf);
        if(insiProf > 0) {printInsiProf = "+" + to_string(insiProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -151,
                117);
        printf("%s\n", printInsiProf.c_str()); 
        



        // intimidation: ---
        // - proficiency marker
        int intimProf= ChaMod;
        if(SkillList[7]==1)
        {
                intimProf = intimProf + pb;
                SkillList[7] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -160 107.5\n");
        }
        // - bonus 
        string printIntimProf = to_string(intimProf);
        if(intimProf > 0) {printIntimProf = "+" + to_string(intimProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -151,
                110);
        printf("%s\n", printIntimProf.c_str()); 




        // investigation: ---
        // - proficiency marker
        int invProf= IntMod;
        if(SkillList[8]==1)
        {
                invProf = invProf + pb;
                SkillList[8] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -160 100.25\n");
        }
        // - bonus 
        string printInvProf = to_string(invProf);
        if(invProf > 0) {printInvProf = "+" + to_string(invProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -151,
                103);
        printf("%s\n", printInvProf.c_str()); 




        // medicine: ---
        // - proficiency marker
        int medProf= WisMod;
        if(SkillList[9]==1)
        {
                medProf = medProf + pb;
                SkillList[9] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -105 158.25\n");
        }
        // - bonus 
        string printMedProf = to_string(medProf);
        if(medProf > 0) {printMedProf = "+" + to_string(medProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -96,
                159);
        printf("%s\n", printMedProf.c_str()); 




        // nature: ---
        // - proficiency marker
        int natProf= WisMod;
        if(SkillList[10]==1)
        {
                natProf = natProf + pb;
                SkillList[10] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -105 151\n");
        }
        // - bonus 
        string printNatProf = to_string(natProf);
        if(natProf > 0) {printNatProf = "+" + to_string(natProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -96,
                152);
        printf("%s\n", printNatProf.c_str()); 




        // perception: ---
        // - proficiency marker
        int perProf= WisMod;
        if(SkillList[11]==1)
        {
                perProf = perProf + pb;
                SkillList[11] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -105 143.75\n");
        }
        // - bonus 
        string printPerProf = to_string(perProf);
        if(perProf > 0) {printPerProf = "+" + to_string(perProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -96,
                145);
        printf("%s\n", printPerProf.c_str()); 
        // passive perception ---
        string printPassivePerception = to_string(perProf); 
        if(perProf>0) {printPassivePerception = "+" + to_string(perProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                18,
                85,
                330);
        printf("%s\n", printPassivePerception.c_str());




        // performance: ---
        // - proficiency marker
        int perfProf= ChaMod;
        if(SkillList[12]==1)
        {
                perfProf = perfProf + pb;
                SkillList[12] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -105 136.5\n");
        }
        // - bonus 
        string printPerfProf = to_string(perfProf);
        if(perfProf > 0) {printPerfProf = "+" + to_string(perfProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -96,
                138);
        printf("%s\n", printPerfProf.c_str()); 




        // persuasion: ---
        // - proficiency marker
        int persProf= ChaMod;
        if(SkillList[13]==1)
        {
                persProf = persProf + pb;
                SkillList[13] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -105 129.25\n");
        }
        // - bonus 
        string printPersProf = to_string(persProf);
        if(persProf > 0) {printPersProf = "+" + to_string(persProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -96,
                131);
        printf("%s\n", printPersProf.c_str()); 




        // religion: ---
        // - proficiency marker
        int relProf= WisMod;
        if(SkillList[14]==1)
        {
                relProf = relProf + pb;
                SkillList[14] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -105 122\n");
        }
        // - bonus 
        string printRelProf = to_string(relProf);
        if(relProf > 0) {printRelProf = "+" + to_string(relProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -96,
                124);
        printf("%s\n", printRelProf.c_str()); 




        // sleight of hand: ---
        // - proficiency marker
        int sohProf= DexMod;
        if(SkillList[15]==1)
        {
                sohProf = sohProf + pb;
                SkillList[15] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -105 114.75\n");
        }
        // - bonus 
        string printSohProf = to_string(sohProf);
        if(sohProf > 0) {printSohProf = "+" + to_string(sohProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -96,
                117);
        printf("%s\n", printSohProf.c_str()); 




        // stealth: ---
        // - proficiency marker
        int steaProf= DexMod;
        if(SkillList[16]==1)
        {
                steaProf = steaProf + pb;
                SkillList[16] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -105 107.5\n");
        }
        // - bonus 
        string printSteaProf = to_string(steaProf);
        if(steaProf > 0) {printSteaProf = "+" + to_string(steaProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -96,
                110);
        printf("%s\n", printSteaProf.c_str()); 
        



        // survival: ---
        // - proficiency marker
        int survProf= WisMod;
        if(SkillList[17]==1)
        {
                survProf = survProf + pb;
                SkillList[17] = 0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -105 100.25\n");
        }
        // - bonus 
        string printSurvProf = to_string(survProf);
        if(survProf > 0) {printSurvProf = "+" + to_string(survProf);}
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                12,
                -96,
                103);
        printf("%s\n", printSurvProf.c_str());  




        // !----------------------END skill proficiency bonuses:---------------------!

        // armor proficiency markers:
        // - shield
        if(ArmorList[0]==1)
        {
                ArmorList[0]=0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -77 77\n");  
        }
        // - light
        if(ArmorList[1]==1)
        {
                ArmorList[1]=0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -139.5 77\n");  
        }
        // - medium
        if(ArmorList[2]==1)
        {
                ArmorList[2]=0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -120 77\n");  
        }
        // - heavy
        if(ArmorList[3]==1)
        {
                ArmorList[3]=0;
                printf("newcurve marktype circle marksize 2.5 2.5 fill 0.5 pts -98 77\n");  
        }

        // proficient weapons listing:
        string firstLine = "";
        string secondLine = "";
        for(long unsigned int i=0; i < WeaponList.size(); i++)
        {
                if (i == WeaponList.size()-1) 
                {
                        if (i<5)
                        {
                                firstLine = firstLine + "" + WeaponList[i];
                        }
                        else
                        {
                                secondLine = secondLine + "" + WeaponList[i];
                        }
                }
                else if (i<5)
                {
                        firstLine = firstLine + WeaponList[i] + ", ";
                }
                else
                {
                        secondLine = secondLine + WeaponList[i] + ", ";
                }
        }
        printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                10,
                -160,
                62);
        printf("%s\n", firstLine.c_str()); 
        printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                10,
                -160,
                50);
        printf("%s\n", secondLine.c_str()); 

        // proficient tools listing:
        string firstToolLine = "";
        string secondToolLine = "";
        for(long unsigned int i=0; i < ToolList.size(); i++)
        {
                if (i == ToolList.size()-1) 
                {
                        if (i<3)
                        {
                                firstToolLine = firstToolLine + "" + ToolList[i];
                        }
                        else
                        {
                                secondToolLine = secondToolLine + "" + ToolList[i];
                        }
                }
                else if (i<3)
                {
                        firstToolLine = firstToolLine + ToolList[i] + ", ";
                }
                else
                {
                        secondToolLine = secondToolLine + ToolList[i] + ", ";
                }
        }
        printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                10,
                -160,
                32);
        printf("%s\n", firstToolLine.c_str()); 
        printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                8,
                -160,
                20);
        printf("%s\n", secondToolLine.c_str()); 

        // equipped listing
        for(long unsigned int i=0; i < EquippedList.size(); i++)
        {
                // print name
                // atk bonus
                // damage/type
                // notes
                switch(i)
                {
                        case 0:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        11,
                                        -51,
                                        299);
                                printf("%s\n", EquippedList[i][0].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                                        10,
                                        2,
                                        299);
                                printf("%s\n", EquippedList[i][1].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        18,
                                        299);
                                printf("%s\n", EquippedList[i][2].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        56,
                                        299);
                                printf("%s\n", EquippedList[i][3].c_str()); 
                                break;
                        case 1:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        11,
                                        -51,
                                        287);
                                printf("%s\n", EquippedList[i][0].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                                        10,
                                        2,
                                        287);
                                printf("%s\n", EquippedList[i][1].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        18,
                                        287);
                                printf("%s\n", EquippedList[i][2].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        56,
                                        287);
                                printf("%s\n", EquippedList[i][3].c_str()); 
                                break;
                        case 2:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        11,
                                        -51,
                                        276);
                                printf("%s\n", EquippedList[i][0].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                                        10,
                                        2,
                                        276);
                                printf("%s\n", EquippedList[i][1].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        18,
                                        276);
                                printf("%s\n", EquippedList[i][2].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        56,
                                        276);
                                printf("%s\n", EquippedList[i][3].c_str()); 
                                break;
                        case 3:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        11,
                                        -51,
                                        264);
                                printf("%s\n", EquippedList[i][0].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                                        10,
                                        2,
                                        264);
                                printf("%s\n", EquippedList[i][1].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        18,
                                        264);
                                printf("%s\n", EquippedList[i][2].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        56,
                                        264);
                                printf("%s\n", EquippedList[i][3].c_str()); 
                                break;
                        case 4:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        11,
                                        -51,
                                        253);
                                printf("%s\n", EquippedList[i][0].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                                        10,
                                        2,
                                        253);
                                printf("%s\n", EquippedList[i][1].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        18,
                                        253);
                                printf("%s\n", EquippedList[i][2].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        56,
                                        253);
                                printf("%s\n", EquippedList[i][3].c_str()); 
                                break;
                        case 5:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        11,
                                        -51,
                                        241);
                                printf("%s\n", EquippedList[i][0].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                                        10,
                                        2,
                                        241);
                                printf("%s\n", EquippedList[i][1].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        18,
                                        241);
                                printf("%s\n", EquippedList[i][2].c_str()); 
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        56,
                                        241);
                                printf("%s\n", EquippedList[i][3].c_str()); 
                                break;
                        default:
                                break;
                }
        }


        // cfeat title
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                13,
                20,
                230);
        printf("%s\n", "CLASS FEATURES"); 

        // cfeat listing
        for(long unsigned int i=0; i < CFeatList.size() && i < 6; i++)
        {
                switch(i)
                {
                        case 0:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        220);
                                printf("%s\n", CFeatList[i].c_str()); 
                                break;
                        case 1:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        210);
                                printf("%s\n", CFeatList[i].c_str()); 
                                break;
                        case 2:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        200);
                                printf("%s\n", CFeatList[i].c_str()); 
                                break;
                        case 3:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        190);
                                printf("%s\n", CFeatList[i].c_str()); 
                                break;
                        case 4:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        180);
                                printf("%s\n", CFeatList[i].c_str()); 
                                break;
                        case 5:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        170);
                                printf("%s\n", CFeatList[i].c_str()); 
                                break;
                        default:
                                break;
                }
        }


        // sfeat title
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                13,
                20,
                158);
        printf("%s\n", "CLASS FEATURES"); 

        // sfeat listing
        for(long unsigned int i=0; i < SFeatList.size() && i < 6; i++)
        {
                switch(i)
                {
                        case 0:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        148);
                                printf("%s\n", SFeatList[i].c_str()); 
                                break;
                        case 1:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        138);
                                printf("%s\n", SFeatList[i].c_str()); 
                                break;
                        case 2:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        128);
                                printf("%s\n", SFeatList[i].c_str()); 
                                break;
                        case 3:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        118);
                                printf("%s\n", SFeatList[i].c_str()); 
                                break;
                        case 4:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        108);
                                printf("%s\n", SFeatList[i].c_str()); 
                                break;
                        case 5:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        98);
                                printf("%s\n", SFeatList[i].c_str()); 
                                break;
                        default:
                                break;
                }
        }



        // feat title
        printf("newstring font Times-Roman fontsize %d x %d y %d hjc vjc :\n",
                13,
                20,
                86);
        printf("%s\n", "CLASS FEATURES"); 

        // feat listing
        for(long unsigned int i=0; i < FeatList.size() && i < 6; i++)
        {
                switch(i)
                {
                        case 0:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        76);
                                printf("%s\n", FeatList[i].c_str()); 
                                break;
                        case 1:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        66);
                                printf("%s\n", FeatList[i].c_str()); 
                                break;
                        case 2:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        56);
                                printf("%s\n", FeatList[i].c_str()); 
                                break;
                        case 3:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        46);
                                printf("%s\n", FeatList[i].c_str()); 
                                break;
                        case 4:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        36);
                                printf("%s\n", FeatList[i].c_str()); 
                                break;
                        case 5:
                                printf("newstring font Times-Roman fontsize %d x %d y %d hjl vjc :\n",
                                        10,
                                        -51,
                                        26);
                                printf("%s\n", FeatList[i].c_str()); 
                                break;
                        default:
                                break;
                }
        }


        // done graphing character sheet.
        return 0;
}
