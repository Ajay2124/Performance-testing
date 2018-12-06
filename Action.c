Action()
{

	web_set_sockets_option("SSL_VERSION", "TLS");
	
	web_set_max_html_param_len("99999");


	web_add_cookie("_ga=GA1.2.862548645.1541663387; DOMAIN={P_URL}");

	web_add_cookie("_gid=GA1.2.951904832.1542009366; DOMAIN={P_URL}");

	web_add_cookie("LPVID=Q4NzQ3YjA5ZTE0MGUzYTkx; DOMAIN={P_URL}");

	web_url("{P_URL}", 
		"URL=https://{P_URL}/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("global.css", 
		"URL=https://{P_URL}/dist/css/global.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t4.inf", 
		LAST);

	web_url("edassist.core.js", 
		"URL=https://{P_URL}/dist/js/edassist.core.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t5.inf", 
		LAST);

	web_url("vendor.core.js", 
		"URL=https://{P_URL}/dist/js/vendor.core.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t6.inf", 
		LAST);

	web_url("select.css", 
		"URL=https://{P_URL}/dist/css/select.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t7.inf", 
		LAST);

	web_url("grunticon.loader.js", 
		"URL=https://{P_URL}/dist/assets/icons/grunticon.loader.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t14.inf", 
		LAST);

	web_url("env.js", 
		"URL=https://{P_URL}/dist/js/env.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t18.inf", 
		LAST);

	web_concurrent_end(NULL);
 

	web_url("footerLogo_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/content/general/components/site/names/footerLogo?cascade=false&client=global&program=&textOnly=false", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t25.inf", 
		LAST);

 

	web_url("lr5tu5demo_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/content/general/login/lr5tu5demo?textOnly=false", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t27.inf", 
		LAST);
 
	

	lr_start_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR01_Login");
 

	web_add_cookie("_ga=GA1.2.862548645.1541663387; DOMAIN=svc-uat.edassist.com");

	web_add_cookie("_gid=GA1.2.951904832.1542009366; DOMAIN=svc-uat.edassist.com");

	web_add_cookie("LPVID=Q4NzQ3YjA5ZTE0MGUzYTkx; DOMAIN=svc-uat.edassist.com");

	web_add_cookie("_gat=1; DOMAIN=svc-uat.edassist.com");

	web_add_cookie("citrix_ns_id=wf92DODJmKRuP96KTJhToLok/4s0000; DOMAIN=svc-uat.edassist.com");

	web_add_cookie("citrix_ns_id_.edassist.com_%2F_wlf=AAAAAAX8C13MMeNAEZZ6-9t0xPEbRrWFec6LD4CobVb-RCmDMzaosOUuq-E27SNLlirzsbbcvNpbWScMAvWcKDN9AGnN&; DOMAIN=svc-uat.edassist.com");

	web_set_user("{P_UserName}","{P_Password}","{P_SubURL}");
	
	web_reg_save_param("Token",
	                   "LB=\"tokens\":{\"sessionToken\":\"",
	                   "RB=\",\"refresh",
	                   LAST);
	
	web_reg_save_param("ParticipantID",
	                   "LB=\"participantId\":",
	                   "RB=,\"",
	                   LAST);
	
	
	
	web_custom_request("login_2",
		"URL=https://svc-uat.edassist.com/ed5/api/v1/sessions/login", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t31.inf", 
		"Mode=HTTP", 
		"EncType=application/json;charset=utf-8", 
		"Body={\"name\":\"{P_UserName}\",\"password\":\"{P_Password}\",\"clientId\":232}", 
		LAST);
 
		
			web_add_header("X-AUTH-TOKEN","{Token}");
			
			web_reg_find("Text=Student Loan Repayment", "SaveCount=Login_Count", LAST);

	web_url("product-types_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/clients/232/participants/{ParticipantID}/product-types", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t33.inf", 
		LAST);
			
			if (atoi(lr_eval_string("{Login_Count}")) > 0)
	
	{

	lr_end_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR01_Login",LR_PASS);
	
	}
	
	else
		
	{

	lr_end_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR01_Login",LR_FAIL);
	
	}
	
	lr_think_time(10);

	 

	lr_start_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR02_ClickStudentLoanRepay");
 
			web_add_header("X-AUTH-TOKEN","{Token}");

	web_url("participantEligibilityCheck_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/participants/{ParticipantID}/participantEligibilityCheck?productTypeId=2", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t35.inf", 
		LAST);
			
 
						
	web_add_header("X-AUTH-TOKEN","{Token}");

	//web_concurrent_start(NULL);
	
	web_reg_find("Text=Company Policy", "SaveCount=HomePage_Count", LAST);

	web_url("home_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/content/loan/components/home?client=232", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t39.inf", 
		LAST);
	
		web_add_header("X-AUTH-TOKEN","{Token}");
		
		web_reg_save_param("OtherStudentLoans",
		                   "LB=\"id\":",
		                   "RB=,\"participantId\":",
		                   "ORD=ALL",
		                   LAST);

	web_url("student-loans_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/participants/{ParticipantID}/student-loans?deleteInStatus90=true", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t40.inf", 
		LAST);
		
		lr_save_string(lr_paramarr_random("OtherStudentLoans"),"RandomParam");
		
		 
			web_add_header("X-AUTH-TOKEN","{Token}");

	 

	web_url("welcomeBanner_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/content/loan/components/home/names/welcomeBanner?client=232", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t43.inf", 
		LAST);
	
		web_add_header("X-AUTH-TOKEN","{Token}");

	web_url("estimatedSavingsHeader_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/content/loan/components/home/names/estimatedSavingsHeader?client=232&program=&textOnly=true", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t44.inf", 
		LAST);
		
			 
	
	if (atoi(lr_eval_string("{HomePage_Count}")) > 0)
	
	{

	lr_end_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR02_ClickStudentLoanRepay",LR_PASS);
	
	}
	
	else
		
	{

	lr_end_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR02_ClickStudentLoanRepay",LR_FAIL);
	
	}
	
		lr_think_time(10);

  

	lr_start_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR03_ClickEdit");
	
 
		
			web_add_header("X-AUTH-TOKEN","{Token}");
			
			web_reg_save_param("ID",
			                   "LB=\"id\":",
			                   "RB=,\"number\":",
			                   "ORD=1",
			                   LAST);
			                   

	web_url("{RandomParam}_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/applications/student-loans/{RandomParam}", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t47.inf", 
		LAST);
			
		 
	
		web_add_header("X-AUTH-TOKEN","{Token}");

	web_url("types_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/student-loan/types", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t51.inf", 
		LAST);

 
			web_add_header("X-AUTH-TOKEN","{Token}");
			
 
			
			web_reg_save_param("LoanID",
			                   "LB=\"id\":",
			                   "RB=,\"gradePointAverage",
			                   "ORD=1",
			                    LAST);
			                      

	web_url("{ID}_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/applications/{ID}", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t53.inf", 
		LAST);
			
		 
				
					web_add_header("X-AUTH-TOKEN","{Token}");

	web_url("loan-servicers_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/loan-servicers", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t55.inf", 
		LAST);
					
 
							
								web_add_header("X-AUTH-TOKEN","{Token}");

	 

	web_url("submitDocsAdditionalInfo_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/content/loan/components/loanAppStep3/names/submitDocsAdditionalInfo?cascade=true&client=232&program=1418&textOnly=false", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t58.inf", 
		LAST);
	
		web_add_header("X-AUTH-TOKEN","{Token}");

	web_url("application-eligible-document-types_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/applications/{ID}/application-eligible-document-types", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t59.inf", 
		LAST);
 
		
			web_add_header("X-AUTH-TOKEN","{Token}");

	web_url("addressAgreementInstructions_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/content/loan/components/loanAppStep3/names/addressAgreementInstructions?client=232", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t61.inf", 
		LAST);
			
 
				
					web_add_header("X-AUTH-TOKEN","{Token}");

	web_reg_find("Search=Body","Text=Documents must be submitted", "SaveCount=SubmitDocs_Count", LAST);

	web_url("submitDocsIntro_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/content/general/components/submitDocs/names/submitDocsIntro?client=232&program=1418", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t63.inf", 
		LAST);
					
 

		web_add_header("X-AUTH-TOKEN","{Token}");

	web_url("grades_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/grades", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t65.inf", 
		LAST);
		
 
		
		if (atoi(lr_eval_string("{SubmitDocs_Count}")) > 0)
	
	{

	lr_end_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR03_ClickEdit",LR_PASS);
	
	}
	
	else
		
	{

	lr_end_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR03_ClickEdit",LR_FAIL);
	
	}
	
		lr_think_time(10);

	 

	lr_start_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR04_ClickSave");
 
		
			web_add_header("X-AUTH-TOKEN","{Token}");

	web_add_cookie("LPSID-9125027=sO5rv9rfQr-OB0IRSvW7rA; DOMAIN=svc-uat.edassist.com");
	
 

	web_add_header("X-AUTH-TOKEN","{Token}");

	web_url("student-loans_3", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/participants/{ParticipantID}/student-loans?deleteInStatus90=true", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t72.inf", 
		LAST);
	
		web_add_header("X-AUTH-TOKEN","{Token}");

	web_url("{RandomParam}_3", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/applications/student-loans/{RandomParam}", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t73.inf", 
		LAST);
		
 
	web_add_header("X-AUTH-TOKEN","{Token}");

	lr_end_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR04_ClickSave",LR_AUTO);
	
		lr_think_time(10);

	

	lr_start_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR05_StopPayLoan");
	
 
			web_add_header("X-AUTH-TOKEN","{Token}");

	web_custom_request("stop-paying-loan_2", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/loan-requests/{LoanID}/stop-paying-loan", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t80.inf", 
		"Mode=HTTP", 
		"EncType=application/json;charset=utf-8", 
		"Body={\"comment\":\"{Comment}\"}", 
		LAST);

		web_add_header("X-AUTH-TOKEN","{Token}");

	web_reg_find("Search=Body","Text=participantId", "SaveCount=StudentLoans_Count", LAST);

	web_url("student-loans_4", 
		"URL=https://svc-uat.edassist.com/ed5/api/v1/participants/{ParticipantID}/student-loans?deleteInStatus90=true", 
		"Resource=1", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t81.inf", 
		LAST);
		
	
	
	
 
		
		if (atoi(lr_eval_string("{StudentLoans_Count}")) > 0)
	
	{

	lr_end_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR05_StopPayLoan",LR_PASS);
	
	}
	
	else
		
	{

	lr_end_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR05_StopPayLoan",LR_FAIL);
	
	}
	
		lr_think_time(10);

	 

	lr_start_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR06_LogOut");
	
	web_add_header("X-AUTH-TOKEN", 
		"{Token}");
	
	web_url("estimatedSavingsHeader", 
		"URL=https://{P_SubURL}/ed5/api/v1/content/loan/components/home/names/estimatedSavingsHeader?client=232&program=&textOnly=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{P_URL}/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("BH_LR_SC06_LoanEditAndSaveLoan_TR06_LogOut",LR_AUTO);
	

	return 0;
}