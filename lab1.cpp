#include <iostream>
#include <cstring>

class Text
{
private:
    std::string text;  // Поле для зберігання послідовності символів
    std::string theme; // Поле для зберігання тематики вказаного тексту

public:
    // Конструктор для встановлення тексту і тематики
    Text(const std::string &txt, const std::string &thm) : text(txt), theme(thm) {}

    // Метод для визначення кількості букв у тексті
    int countLetters() const
    {
        int count = 0;
        for (char c : text)
        {
            if (isalpha(c))
            {
                count++;
            }
        }
        return count;
    }

    // Метод для визначення кількості пробілів (між словами один пробіл)
    int countSpaces() const
    {
        int count = 0;
        for (char c : text)
        {
            if (c == ' ')
            {
                count++;
            }
        }
        return count;
    }

    // Метод для заміни кожного входження одного символа на інший
    void replaceLetter(char oldChar, char newChar)
    {
        for (char &c : text)
        {
            if (c == oldChar)
            {
                c = newChar;
            }
        }
    }

    // Метод для видалення слова з вказаним порядковим номером
    void deleteWord(int wordIndex)
    {
        int currentWordIndex = 0;
        int wordStart = -1, wordEnd = -1;
        bool inWord = false;

        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] != ' ' && !inWord)
            {
                // Початок нового слова
                inWord = true;
                if (currentWordIndex == wordIndex)
                {
                    wordStart = i;
                }
            }
            if ((text[i] == ' ' || i == text.length() - 1) && inWord)
            {
                // Кінець поточного слова
                inWord = false;
                if (currentWordIndex == wordIndex)
                {
                    wordEnd = (i == text.length() - 1) ? i + 1 : i;
                    break;
                }
                currentWordIndex++;
            }
        }

        // Якщо знайшли потрібне слово, видаляємо його
        if (wordStart != -1 && wordEnd != -1)
        {
            text.erase(wordStart, wordEnd - wordStart);
        }

        // Видаляємо зайві пробіли після видалення слова
        while (text.find("  ") != std::string::npos)
        {
            text.erase(text.find("  "), 1); // Видаляємо подвійні пробіли
        }

        // Видаляємо пробіл на початку рядка, якщо він є
        if (!text.empty() && text[0] == ' ')
        {
            text.erase(0, 1);
        }

        // Видаляємо пробіл в кінці рядка, якщо він є
        if (!text.empty() && text[text.length() - 1] == ' ')
        {
            text.erase(text.length() - 1, 1);
        }
    }

    // Метод для виведення тексту
    void displayText() const
    {
        std::cout << "Text: " << text << std::endl;
    }

    // Метод для виведення тематики
    void displayTheme() const
    {
        std::cout << "Topic: " << theme << std::endl;
    }
};

int main()
{
    // Створюємо об'єкт класу Text
    Text myText("Nice to meet you, where you been?", "Example of text");

    // Виводимо початковий текст і тематику
    myText.displayText();
    myText.displayTheme();

    // Визначаємо кількість букв у тексті
    std::cout << "Amount of letters: " << myText.countLetters() << std::endl;

    // Визначаємо кількість пробілів
    std::cout << "Amount of spaces: " << myText.countSpaces() << std::endl;

    // Замінюємо букву "e" на "o"
    myText.replaceLetter('e', 'o');
    myText.displayText();

    // Видаляємо слово з порядковим номером 3
    myText.deleteWord(3);
    myText.displayText();

    return 0;
}