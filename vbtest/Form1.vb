Imports System.Runtime.InteropServices
Public Class Form1
    <DllImport("TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GapCalculate(ByVal w As Int32, ByVal x As Int32, ByVal l As Single, ByVal r As Single, ByVal resultStr As String) As Int32


    End Function
    <DllImport("TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function Authorized() As Int32




    End Function
    <DllImport("TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function CreateKey(ByVal a As String, ByVal b As String) As Int32

    End Function
    <DllImport("TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function RingCalculate(ByVal n As Int32, ByVal w As Int32, ByVal dr As Int32, ByVal lxj As Int32, ByVal l0 As Int32, ByVal l1 As Int32, ByVal l2 As Int32, ByVal l3 As Int32, ByVal l4 As Int32, ByVal l5 As Int32, ByVal resultStr As String) As Int32

    End Function
    Private Sub GapCal_Click(sender As Object, e As EventArgs) Handles GapCal.Click
        Dim resultStr As String
        resultStr = Space(128)
        Dim charNum = GapCalculate(TextGapw.Text(), TextGapx.Text(), TextGapl.Text(), TextGapr.Text, resultStr)
        resultStr = Microsoft.VisualBasic.Left(resultStr, charNum)
        Dim d As Int32
        Dim x As Int32
        Dim strList = resultStr.Split(",")
        d = Convert.ToSingle(strList(0))
        x = Convert.ToSingle(strList(1))
        MessageBox.Show("d is " + strList(0) + "; x is " + strList(1))

    End Sub

 
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Btn_Authorized.Click
        Dim result = Authorized()
        MessageBox.Show(result)
    End Sub

    Private Sub Button1_Click_1(sender As Object, e As EventArgs) Handles Button1.Click
        Dim result = CreateKey("c:\shield\monitor\soft_data\ver_id.txt", "c:\shield\monitor\machin_coad.txt")
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
       
        Dim resultStr As String
        resultStr = Space(128)
        Dim charNum = RingCalculate(4, 1200, 5, 1, 500, 500, 500, 2500, 0, 0, resultStr)
        resultStr = Microsoft.VisualBasic.Left(resultStr, charNum)
        Dim strList = resultStr.Split(",")
        Dim ring = Convert.ToInt32(strList(0))
        Dim jxc = Convert.ToInt32(strList(1))
        Dim dr = Convert.ToInt32(strList(2))
        MessageBox.Show("ring is " + ring.ToString() + "; jxc is " + jxc.ToString() + "; dr is " + dr.ToString())
    End Sub
End Class
