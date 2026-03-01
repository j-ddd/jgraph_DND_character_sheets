  # DJDC format (Dodd Jgraph DnD Character format)

- All text assumes raw strings with no headers or leading words for the first 23 lines.
- To the left of input word, I've included line numbers to make it easier to read, 
but line numbers should not be included in the actual djdc file.
- Additionally, I've added what data types the program will expect as inputs.

(Examples can be found in the djdc folder.)

*Note: I'd be remiss to not mention that any character sheet generated with this should be verified by the DM running your campaign.*

- 1 Name - `String`
- 2 Background - `String`
- 3 Species - `String`
- 4 Class - `String`
- 5 Subclass - `String`
- 6 Level - (Put `0` if brand new character) - `int`
- 7 XP - (Put `0` if brand new character) - `Cannot be negative` - `int`
- 8 AC (Armor Class) - (Will only accepts ints equal to or greater than `5`) - `int`
- 9 Current HP - `Cannot be negative` - `int` 
- 10 Temp HP - (Put `0` if brand new character) - `Cannot be negative` - `int`
- 11 Max HP - `Cannot be negative` - `int`
- 12 Heroic Inspiration - (Will only accept `0` for no, or `1` for yes) `int` 
- 13 Strength Score - (Will only accepts ints between `1` up to `30`) - `int`
- 14 Dexterity Score - (Will only accepts ints between `1` up to `30`) - `int`
- 15 Constitution Score - (Will only accepts ints between `1` up to `30`) - `int`
- 16 Intelligence Score - (Will only accepts ints between `1` up to `30`) - `int`
- 17 Wisdom Score - (Will only accepts ints between `1` up to `30`) - `int`
- 18 Charisma Score - (Will only accepts ints between `1` up to `30`) - `int`
- 19 Size - (Leave as `M` for medium, unless you are a small species like `Goblin`. Then put `S` for small) - `char`
- 20 Speed - (Leave as `30` if not playing a species that affects your movement speed. Fly/Swim speed will be in features) - `int`

*From here on out, you will need to put a header in front of the description for the next few things.* 
*Also, note that spelling will need to be exactly correct for all headers*

*1-4 Entries Armor Proficiencies*  - *HEADER* -> `ARMORS` - (Please put as a list of armors and/or shield: `Light` `Medium` `Heavy` `Shield`. Note, the spelling will need to be exactly correct here.) - `String(s)`
Example:
- ARMORS
- Shield
- Light
- Medium
- Heavy

*1-10 Entries Weapon Proficiencies* - *HEADER* -> `WEAPONS` -(Please input weapon proficiencies as you'd like them to be displayed. Ex: `Simple` `Martial` `Simple` `Battleaxe` `Longsword`. I do limit this to ten entries for brevities sake, so please just put the most relevat ones.) - `String(s)` 
Example:
- WEAPONS
- Simple
- Battleaxe
- Greatsword
- Longbow

*0-24 Entries Skill and Save Proficiencies* - *HEADER* -> `SKILLS` (Please enter a list of all skills that the character is proficient in. Note, the spelling will need to be exactly correct here.) - `String(s)`
Example:
- SKILLS
- Athletics
- Survival
- AnimalHandling
- SleightOfHand
- StrSave
- DexSave

*1-5 Entries Tool Proficiencies* - *HEADER* -> `TOOLS` - (Please input tool proficiencies as you'd like them to be displayed. Ex: `Thieves` `Cartographers` `Leather` `Smithing`. I do limit this to five entries for brevities sake, so please just put the most relevat ones.) - `String(s)` 
Example:
- TOOLS
- Thieves
- Cartographers
- Leather
- Smithing

*1-6 Entries Equipped Weapon/Cantrip*: *HEADER* -> `EQUIPPED`  - `String(s)`
- Weapon name: (Could be anything one-handed, two-handed, a cantrip. Ex: `Shortsword`, `Greatsword`, `Ray of Frost`. Note, I do limit this to 15 characters, so abbreviations may be necesarry.)
- Attack Bonus/DC: (You need to put what the attack modifier is of the weapon/cantrip, or if its a saving throw, add the number of the save with the respective ability score. Ex: `+5`, `+7`, `Wis 13`, `Int 14`. I've limited it to 6 characters, so you may need to abbreviate accordingly.)
- Damage and Type: (This is the damage dice of the attack, along with any modifer you add to it from any source. Ex: `2d6+5 Pierce`, `1d10 Bludg.', `1d10+7 Cold`. I also limit the characters here to 12, so you may need to abbreviate accordingly.)
- Notes: (Any additonal notes for this attack/cantrip, but note that I only allow 20 characters for each entry. Ex: for vicious mockery, you could put `Disadv. on Attack`, or `-10ft speed` for ray of frost. Can leave `None`.)

- Finally, heres an example of what a complete entry would look like. Also, here is where you would put a shield.
Examples:

Shield:
- EQUIPPED
- Shield

Weapon:
- EQUIPPED
- Greatsword
- +7
- 2d6+5 Pierce
- Great Weapon Master

Cantrip:
- EQUIPPED
- Vicious Mockery 
- Wis 13 
- 1d6+3 Psy.
- Disadv. on Attack


*1-? Entries Class Features*: *HEADER* -> `CFEAT` - `String`
- Just raw text of what the class feature is. All together, I limit the amount of text you can have for each line by X characters. In case you want to manipulate how the lines are written, you can by initiating a new CFeat line.
Example:

- CFEAT
- Second Wind (Twice per short rest)
- CFEAT
- Action Surge (Once per short rest)
- CFEAT
- Once per short rest, you may choose one ally. That ally then
- CFEAT
- gains +1d4 to all saving throws until the next long rest.

*1-? Entries Species Features*: *HEADER* -> `SFEAT` - `String`
- Just raw text of what the species feature is. All together, I limit the amount of text you can have for each line by X characters. In case you want to manipulate how the lines are written, you can by initiating a new SFeat line.
Example:

- SFEAT
- Fury of the Small
- SFEAT
- Human Extra Feat


*1-? Entries Feats*: Header: *HEADER* -> `FEAT` - `String`
- Just raw text of what the feat is. All together, I limit the amount of text you can have for each line by X characters. In case you want to manipulate how the lines are written, you can by initiating a new Feat line.
Example:

- FEAT
- Tough
- FEAT
- Ability Score Improvement: +1 Dexterity and
- FEAT
- +1 Charisma

