
import romanNumerals, openpyxl

wb = openpyxl.Workbook()
sheet = wb.active

sheet.cell(1, 1).value = 'Decimal Value'
sheet.cell(1,2).value = 'Python Roman Numeral'
sheet.cell(1,3).value = 'Microsoft Excel Roman Func'
sheet.cell(1, 4).value = 'Test if Equal'

for i in range(2, 40002):

    j = i -1

    sheet.cell(i, 1).value = j

    sheet.cell(i, 2).value = romanNumerals.int2roman(j)

    sheet.cell(i, 3).value = '=ROMAN('+ str(j) + ')'

    sheet.cell(i, 4).value = '=IF(B' + str(i) + '=C' + str(i) + ', "YES", "WRONG")'

wb.save('numerals1-40krev2.xlsx')