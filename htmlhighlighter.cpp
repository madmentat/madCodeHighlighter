#include "htmlhighlighter.h"

#include <KSyntaxHighlighting/Format>
#include <KSyntaxHighlighting/State>

#include <QTextStream>
#include <QDebug>

using namespace KSyntaxHighlighting;

HtmlHighlighter::HtmlHighlighter()
{
    m_theme = m_repository.defaultTheme(Repository::LightTheme);
}

void HtmlHighlighter::setDefinition(const Definition &def)
{
    m_definition = def;
    AbstractHighlighter::setDefinition(def);
}

void HtmlHighlighter::setTheme(const Theme &theme)
{
    m_theme = theme;
    AbstractHighlighter::setTheme(theme);
}

void HtmlHighlighter::setInvertDarkThemeBG(bool enabled)
{
    m_invertDarkThemeBG = enabled;
}

bool HtmlHighlighter::invertDarkThemeBG() const
{
    return m_invertDarkThemeBG;
}

QString HtmlHighlighter::highlightToHtml(const QString &text, int fontSize, double lineSpacing)
{
    m_lines = text.split('\n');
    m_outputHtml.clear();
    m_currentLine = 0;

    QString preStyle = QString(R"(
        font-family: monospace;
        font-size: %1px;
        line-height: %2;
        background-color: #f5f5f5;
        border: 1px solid #ddd;
        border-radius: 4px;
        padding: 10px;
        overflow-x: auto;
    )").arg(fontSize).arg(lineSpacing);

    m_outputHtml += QString("<pre class=\"cpp\" style=\"%1\">\n").arg(preStyle);

    State state;
    for (const QString &line : m_lines) {
        state = highlightLine(QStringView{line}, state);
        m_outputHtml += "<br/>\n";
        ++m_currentLine;
    }

    m_outputHtml += "</pre>";
    return m_outputHtml;
}

void HtmlHighlighter::applyFormat(int offset, int length, const Format &format)
{
    if (m_currentLine >= m_lines.size() || length <= 0 || offset < 0)
        return;

    const QString &line = m_lines[m_currentLine];
    QString textFragment = line.mid(offset, length).toHtmlEscaped();
    if (textFragment.isEmpty())
        return;

    QStringList styles;

    if (format.hasTextColor(m_theme)) {
        styles << QString("color:%1").arg(format.textColor(m_theme).name());
    }
    if (format.isBold(m_theme)) styles << "font-weight:bold";
    if (format.isItalic(m_theme)) styles << "font-style:italic";
    if (format.isUnderline(m_theme)) styles << "text-decoration:underline";

    if (!styles.isEmpty()) {
        m_outputHtml += QString("<span style=\"%1\">%2</span>").arg(styles.join(";"), textFragment);
    } else {
        m_outputHtml += textFragment;
    }
}
