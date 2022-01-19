import gomoku_engine
import PySimpleGUI as sg


sg.theme("DarkAmber")
layout = [[sg.Text("some test on row 1")], [sg.Text("tenter"), sg.InputText()], [sg.Button("OK"), sg.Button("Cancel")]]

window = sg.Window("Window Title", layout)
while True:
    events = window.read()
    if events is not None:
        event, value = events
        if events is not None and (event == sg.WIN_CLOSED or event == "Cancel"):
            break
        print("aaaa", value[0])

window.close()
