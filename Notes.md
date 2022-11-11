# Review: https://trello.com/c/yuDfTvdp/2-build-player-profile-maker
1. Input checking
  1. There is none ---THERE IS NOW.
  2. The input is not well represented. After the user hits "1" for "Man" as thier gender, the "1" is captured,
     but the to recover the knolege that "1" representes the users choice of being a man is difficult later.
     you can user enums or other more contrainted and descritive types (maybe varius custom types) to make the code
     and data more understanble and eiser to work with.
  3. Dont take bad input, if the input is invalid ask for it agian, at least.
  4. Bad input is like bactiria you want to keep it from getting in at all, becasue it harder to deal with once its in.
  ---INPUT CHECKING GOT IT.
2. The code is almost to verbose.
   While is is really clear what it is doing, that is becasue you are constantly using "base" functions and language tools
   with out building any of your own abstrations that higlight patterns that are aprent with the code, this could make it eiser to read, maintain and modify later.
   Also it serervse to help document and establish any concepts you discovered.

Overall really good work, aproving the PR. We can fix them now or create bricks for them so we dont lose track of it.