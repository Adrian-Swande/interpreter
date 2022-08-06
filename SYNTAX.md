# Syntax (utdaterad)

## Variabler

### Variabeldeklaration och tilldelning

Variabler kan deklareras och tilldelas strängar eller heltal. Distinktionen spelar dock endast roll vid tilldelning. Alla variabelvärden lagras intärnt som teckensträngar.

Deklaration och strängtilldelning följer syntaxen:

`ord <variabelnamn> <stränguttryck>`

Syntax för stränguttryck lyder:

`<sträng/variabel> + ...`

Syntax för strängar lyder:

`'<sträng>'`

Deklaration och numerisk tilldelning följer syntaxen:

`tal <variabelnamn> <numeriskt uttryck>`

**Exempel:**

`ord meddelande 'hejsan värld!'`

Konvertering från sträng till heltal sker automatiskt under exekvering. Försök att utföra en heltalsoperation på en sträng som inte kan tolkas som ett heltal resulterar i exekveringsfel och programmet avbryts.

**Exempel:**

```cpp
01| tal a 10
02| print a
03| print a*3
```

1. `a` deklareras och tilldelas `10` vilken sparas i minnet som en sträng av karaktärerna '1', '0'.
2. När funktionen `print` tillkallas skrivs strängen tillkallad `a` ut, härvid då "10".
3. När operatorn `*` tillkallas söker den ett heltal; `a` konverteras då automatiskt från strängen "10" till heltalet 10 så att den kan multipliceras med 3.

### Variabelomfång och referens


