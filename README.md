# Sudoku Solver in C++

Dieses Programm ist ein einfacher Sudoku-Löser, der Backtracking verwendet, um Sudokus zu lösen.

## Features

- Eingabe eines Sudoku über die Konsole
- Anzeige des gelösten Sudokus oder einer Nachricht, wenn keine Lösung gefunden wurde
- Überprüft, ob eine Zahl in einer bestimmten Zeile, Spalte oder einem Quadrat gültig ist

## Anleitung

1. Kompilieren Sie den Code:
   ```
   g++ -o sudoku_solver main.cpp
   ```
2. Führen Sie das Programm aus:
   ```
   ./sudoku_solver
   ```
3. Geben Sie das Sudoku ein:
    - Jede Zeile sollte 9 Zahlen enthalten, getrennt durch Leerzeichen oder andere Zeichen.
    - Verwenden Sie `0` für leere Felder.
    - Nach jeder 3. Zeile (außer der letzten) können Sie eine Trennzeile für die visuelle Darstellung hinzufügen. Das Programm erkennt und ignoriert diese.
    - Beispiel:
      ```
      5 3 0 | 0 7 0 | 0 0 0
      6 0 0 | 1 9 5 | 0 0 0
      0 9 8 | 0 0 0 | 0 6 0
      -----------------------
      8 0 0 | 0 6 0 | 0 0 3
      4 0 0 | 8 0 3 | 0 0 1
      7 0 0 | 0 2 0 | 0 0 6
      -----------------------
      0 6 0 | 0 0 0 | 2 8 0
      0 0 0 | 4 1 9 | 0 0 5
      0 0 0 | 0 8 0 | 0 7 9
      ```
4. Das Programm zeigt das gelöste Sudoku oder eine Nachricht, dass keine Lösung gefunden wurde.

## Funktionen

- `get_sudoku`: Nimmt das Sudoku von der Benutzereingabe entgegen.
- `print_sudoku`: Druckt das Sudoku in einem formatierten Layout.
- `find_empty`: Findet ein leeres Feld im Sudoku und gibt dessen Position zurück.
- `check_row`, `check_column`, `check_square`: Überprüfen, ob eine Zahl in einer bestimmten Zeile, Spalte bzw. Quadrat gültig ist.
- `solve_sudoku`: Versucht, das Sudoku mit Backtracking zu lösen.

Viel Spaß beim Lösen von Sudokus!