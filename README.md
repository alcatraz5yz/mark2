einfacher geht es nicht
- das Konfigurationsfile besteht nur aus cmake => CMakeLists.txt
- cmake hat den vorteil, dass es alle libraries automatisch findet und bessere vscode integration hat
- qt, gcov, gtest, etc. muss installiert sein

um alles laufen zu lassen:

cmake .

make 

./MyProjekt

make doc

make tests

make gcov


todo:
- yaml file für ci integration
- readme besser gestalten mit ci-buttons
- besseres gui
- gtest/mock implementieren
- jira
- pflichtenheft