#ifndef HTMLHIGHLIGHTER_H
#define HTMLHIGHLIGHTER_H

#include <KSyntaxHighlighting/AbstractHighlighter>
#include <KSyntaxHighlighting/Definition>
#include <KSyntaxHighlighting/Theme>
#include <KSyntaxHighlighting/Repository>


class HtmlHighlighter : public KSyntaxHighlighting::AbstractHighlighter
{
public:
    HtmlHighlighter();

    void setDefinition(const KSyntaxHighlighting::Definition &def) override;
    void setTheme(const KSyntaxHighlighting::Theme &theme) override;

    void setInvertDarkThemeBG(bool enabled);
    bool invertDarkThemeBG() const;

    QString highlightToHtml(const QString &text, int fontSize = 14, double lineSpacing = 1.4);

protected:
    void applyFormat(int offset, int length, const KSyntaxHighlighting::Format &format) override;

private:
    KSyntaxHighlighting::Definition m_definition;
    KSyntaxHighlighting::Theme m_theme;
    QStringList m_lines;
    QString m_outputHtml;
    int m_currentLine = 0;
    bool m_invertDarkThemeBG = false;
    KSyntaxHighlighting::Repository m_repository;
};

#endif // HTMLHIGHLIGHTER_H
