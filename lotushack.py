import sys
import serial
from PyQt6.QtWidgets import QApplication, QDialog
from hackathon import Ui_Dialog

class window(QDialog):
    def __init__(self):
        super().__init__()
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)
        self.ui.stackedWidget.setCurrentIndex(0)
        self.ui.pushButton.clicked.connect(lambda: self.ui.stackedWidget.setCurrentIndex(1))
        self.ui.pushButton_7.clicked.connect(lambda: self.ui.stackedWidget.setCurrentIndex(0))
        self.ui.pushButton_5.clicked.connect(lambda: self.ui.stackedWidget.setCurrentIndex(2))
        


        

        self.arduino = None
        self.init_serial()   

    def init_serial(self):
        try:
            
            self.arduino = serial.Serial('/dev/ttyACM1', 9600, timeout=0.1)
            print("Port opened. Arduino may reset...")
        except Exception as e:
            print(f"Connection Error: {e}")

        
        self.ui.pushButton_3.clicked.connect(lambda: self.send_command('R'))
        self.ui.pushButton_4.clicked.connect(lambda: self.send_command('G'))
        self.ui.pushButton_6.clicked.connect(lambda: self.send_command('Y'))
        self.ui.pushButton_12.clicked.connect(lambda: self.send_command("N"))

    def send_command(self, char):
        if self.arduino and self.arduino.is_open:
            try:
                self.arduino.write(char.encode())
                
                self.arduino.flush() 
                print(f"Sent: {char}")
            except Exception as e:
                print(f"Write error: {e}")

app = QApplication(sys.argv)
window = window()
window.show()
sys.exit(app.exec())