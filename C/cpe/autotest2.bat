@TITLE AutoTest Made By Dream_Rhythm

@echo:小提示:
@echo:可在Windows檔案總管中,直接拖入檔案即可!
@echo:
@SET /p exe=請輸入執行檔路徑:
@SET /p data=請輸入測資路徑:


:start
CLS
@echo:以下為程式執行內容
@echo:
@echo:----------------------
@%exe%<%data%
@echo:
@echo:----------------------
@echo:
@echo:按下任意鍵後將重新測試程式
@pause

goto start