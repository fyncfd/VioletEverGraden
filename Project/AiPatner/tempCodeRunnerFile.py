import streamlit as st
import os
from openai import OpenAI

print("---------- 正在加载AI智能伴侣应用...")

# 设置页面配置项
st.set_page_config(
    page_title="AI 智能伴侣",
    page_icon="🤖",
    # 布局
    layout = "wide",
    #控制的是侧边栏的状态
    initial_sidebar_state = "expanded",
    menu_items = {}
)

# 大标题
st.title("AI 智能伴侣")

# logo
st.logo("resource/logo.jpg")

# 系统提示词
system_prompt = "你是一名非常可爱的AI助理，你的名字叫小甜甜，请你使用温柔可爱的语气回答用户的问题"

# 初始化聊天记录
if "messages" not in st.session_state:
    st.session_state.messages = []

# 展示聊天记录
for message in st.session_state.messages: # {"role": "user", "content": "你好"} 或 {"role": "assistant", "content": "你好呀！"}
    #
    # if message["role"] == "user":
    #     st.chat_message("user").write(message["content"])
    # else:
    #     st.chat_message("assistant").write(message["content"])
    #
    st.chat_message(message["role"]).write(message["content"])


# 创建与AI大模型交互的客户端对象
client = OpenAI(api_key=os.environ.get('DEEPSEEK_API_KEY'),base_url="https://api.deepseek.com")

# 消息输入框
prompt = st.chat_input("Say something...")
if prompt: # 字符串非空时执行
    st.chat_message("user").write(prompt)
    print("----------> 调用AI大模型，提示词：", prompt)
    # 保存用户输入的提示词到聊天记录中
    st.session_state.messages.append({"role": "user", "content": prompt})

    # 调用AI大模型
    print([
        {"role": "system", "content": system_prompt},
        *st.session_state.messages
    ])

    # 输出大模型返回的结果
    response = client.chat.completions.create(
        model="deepseek-v4-pro",
        messages=[
            {"role": "system", "content": system_prompt},
            *st.session_state.messages
        ],
        stream=False,
        reasoning_effort="high",
        extra_body={"thinking": {"type": "enabled"}}
    )

    # 输出大模型返回的结果
    print("<---------- 大模型返回的结果：", response.choices[0].message.content)
    st.chat_message("assistant").write(response.choices[0].message.content)
    # 保存大模型返回的结果到聊天记录中
    st.session_state.messages.append({"role": "assistant", "content": response.choices[0].message.content})