import xlrd

book = xlrd.open_workbook("Thumb32.xlsx")

book.sheet_names()

sheet = book.sheet_by_name('CLASS_LDM')

rows = sheet.row_values()
cols = sheet.col_values()

for row in cols:
    mask = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'
    value = '00000000000000000000000000000000'
    mask = list(mask)
    value = list(value)
    cell = sheet.cell_value(0,0)
    cell = cell.replace(' ', '')
    start = cell[cell.index('(') + 1 : cell.index(',')]
    end = cell[cell.index(',') + 1 : cell.index(')')]
    start = int(start);
    end = int(end);