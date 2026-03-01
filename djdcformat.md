  # DJDC format (Dodd Jgraph DnD Character format)

- All text assumes raw strings with no headers or leading words.
- To the left of input word, I've included line numbers to make it easier to read, 
- but line numbers should not be included in the actual djdc file.
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
- 9 Current HP - (Put `0` if brand new character) - `Cannot be negative` - `int` 
- 10 Temp HP - (Put `0` if brand new character) - `Cannot be negative` - `int`
- 11 Max HP - `Cannot be negative` - `int`
- 12 Heroic Inspiration - (Will only accept `0` for no, or `yes`) `int` 
- 13 Strength Score - (Will only accepts ints between `1` up to `30`) - `int`
- 14 Dexterity Score - (Will only accepts ints between `1` up to `30`) - `int`
- 15 Constitution Score - (Will only accepts ints between `1` up to `30`) - `int`
- 16 Intelligence Score - (Will only accepts ints between `1` up to `30`) - `int`
- 17 Wisdom Score - (Will only accepts ints between `1` up to `30`) - `int`
- 18 Charisma Score - (Will only accepts ints between `1` up to `30`) - `int`
- 19 Size - (Leave as `M` for medium, unless you are a small species like `Goblin`. Then put `S` for small) - `char`
- 20 Speed - (Leave as `30` if not playing a species that affects your movement speed. Fly/Swim speed will be in features) - `int`
- 21 Armor Proficiencies - (Please put as spaced list of armors and/or shield: `Light Medium Heavy Shield`) - `String(s)`
- 22 Weapon Proficiencies - (Please input weapon proficiencies as you'd like them to be displayed. Ex: `Simple, Martial` or `Simple, Battleaxe, Longsword') - `String`
- 23 Skill Proficiencies - (Please a spaced list of all skills that the character is proficient in. Note, the spelling will need to be exactly correct here. Ex: `Athletics Survival Perception Insight`

*From here on out, you will need to put a header in front of the description for the next few things.* 
Ex: `Equipped Greatsword Attack Strength

*1-6 Entries Equipped Weapon/Cantrip*: Header: `Equipped`  - `String(s)`
- Weapon name: (Could be anything one-handed, two-handed, a cantrip. Ex: `Shortsword`, `Greatsword`, `Ray of Frost`. Note, I do limit this to 15 characters, so abbreviations may be necesarry.)
- Attack Bonus/DC: (You need to put what the attack modifier is of the weapon/cantrip, or if its a saving throw, add the number of the save with the respective ability score. Ex: `+5`, `+7`, `Wis 13`, `Int 14`. I've limited it to )
- Damage and Type: (This is the damage dice of the attack, along with any modifer you add to it from any source. Ex: `2d6+5 Pierce`, `1d10 Bludg.', `1d10+7 Cold`. I also limit the characters here to 12, so you may need to abbreviate accordingly.)
- Notes: (Any additonal notes for this attack/cantrip, but note that I only allow 20 characters for each entry. Ex: for vicious mockery, you could put `Disadv. on Attack`, or `-10ft speed` for ray of frost. Can leave `None`.)

- Finally, heres an example of what a complete entry would look like. Also, here is where you would put a shield.
- Ex: (`Equipped Shield`, `Equipped Greatsword Attack Strength 2d6+5 Pierce Great Weapon Master`, `Equipped Vicious Mockery Wis 13 1d6+3 Psy. Disadv. on Attack`, )


*1-? Entries Class Features*: Header: `CFeat` - `String`
- Just raw text of what the class feature is. All together, I limit the amount of text you can have for each line by X characters.


*1-? Entries Species Features*: Header: `SFeat` - `String`
- Just raw text of what the species feature is. All together, I limit the amount of text you can have for each line by X characters.


*1-? Entries Feats*: Header: `Feat` - `String`
- Just raw text of what the feat is. All together, I limit the amount of text you can have for each line by X characters.

