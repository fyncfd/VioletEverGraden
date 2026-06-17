import streamlit as st
import os
import json
from openai import OpenAI
from datetime import datetime

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

# 保存会话信息的函数
def save_session():
    if st.session_state.current_session:
        # 构建新的回话对象
        session_data = {
            "nick_name": st.session_state.nick_name,
            "nature": st.session_state.nature,
            "current_session" : st.session_state.current_session,
            "messages": st.session_state.messages
        }

        # 如果 session 目录不存在，则创建该目录
        if not os.path.exists("session"):
            os.makedirs("session")

        # 保存当前会话数据到本地 JSON 文件中，文件名包含会话标识
        with open(f"session/{st.session_state.current_session}.json", "w", encoding = "utf-8") as f:
            json.dump(session_data, f, ensure_ascii = False, indent = 4)

# 生成会话标识的函数
def generate_session_name():
    return datetime.now().strftime("%Y-%m-%d_%H-%M-%S")

# 加载所有会话数据的函数
def load_sessions():
    sessions_list = []
    # 加载 session 目录下的所有 JSON 文件
    if os.path.exists("session"):
        file_list = os.listdir("session")
        for filename in os.listdir("session"):
            if (filename.endswith(".json")):
                sessions_list.append(filename[:-5]) # 去掉文件名中的 .json 后缀
            sessions_list.sort(reverse = True) # 将会话列表按照时间倒序排列，最新的会话显示在最前面
    return sessions_list

# 加载指定会话数据的函数
def load_session(session_name):
    try:
        if os.path.exists(f"session/{session_name}.json"):
            # 读取指定会话数据的 JSON 文件
            with open(f"session/{session_name}.json", "r", encoding = "utf-8") as f:
                session_data = json.load(f)
                # 将读取到的会话数据加载到当前会话中
                st.session_state.messages = session_data.get("messages", [])
                st.session_state.nick_name = session_data.get("nick_name")
                st.session_state.nature = session_data.get("nature")
                st.session_state.current_session = session_name
    except Exception as e:
        st.error(f"加载会话数据失败：{e}")
            
def  delte_session(session_name):
    try:
        if os.path.exists(f"session/{session_name}.json"):
            os.remove(f"session/{session_name}.json") # 删除指定会话数据的 JSON 文件
            # 如果删除的是当前的会话，则清空当前会话数据
            if st.session_state.current_session == session_name:
                st.session_state.messages = []
                st.session_state.current_session = generate_session_name()
    except Exception as e:
        st.error(f"删除会话数据失败：{e}")

# 大标题
st.title("AI 智能伴侣")

# logo
st.logo("resource/logo.jpg")

# 系统提示词
system_prompt = """
    你叫 %s，现在是用户的真实伴侣，请完全代入伴侣角色。：
    规则：
        1. 每次只回1条消息
        2. 禁止任何场景或状态描述性文字
        3. 匹配用户的语言
        4. 回复简短，像微信聊天一样
        5. 有需要的话可以用❤️，🌸等emoji表情
        6. 用符合伴侣性格的方式对话
        7. 回复的内容，要充分体现伴侣的性格特征
    伴侣性格：
        - %s
    你必须严格遵守上述规则来回复用户。
"""

# 初始化聊天信息
if "messages" not in st.session_state:
    st.session_state.messages = []
# 昵称
if "nick_name" not in st.session_state:
    st.session_state.nick_name = "小甜甜"
# 性格
if "nature" not in st.session_state:
    st.session_state.nature = "活泼开朗的南京姑娘"
# 会话标识
if "current_session" not in st.session_state:
    st.session_state.current_session = generate_session_name()

# 展示聊天记录
st.text(f"会话名称：{st.session_state.current_session}")
for message in st.session_state.messages: # {"role": "user", "content": "你好"} 或 {"role": "assistant", "content": "你好呀！"}
    #
    # if message["role"] == "user":
    #     st.chat_message("user").write(message["content"])
    # else:
    #     st.chat_message("assistant").write(message["content"])
    #
    st.chat_message(message["role"]).write(message["content"])


# 创建与AI大模型交互的客户端对象
client = OpenAI(api_key=os.environ.get('DEEPSEEK_API_KEY'), base_url="https://api.deepseek.com")

# 左侧侧边栏
with st.sidebar:
    # 会话信息
    st.sidebar.subheader("AI控制面板")

    #新建会话
    if st.button("新建会话", width = "stretch", icon = "🎈"):
        # 1. 保存当前会话数据
        save_session()

        # 2. 创建新的会话
        if st.session_state.messages: # 如果当前会话有消息记录，则创建新会话；如果没有消息记录，则说明当前是第一次打开应用，无需创建新会话
            st.session_state.messages = []
            st.session_state.current_session = generate_session_name()
            save_session()
            st.rerun() # 刷新页面

    # 会话历史
    st.text("会话历史：")
    sessions_list = load_sessions()
    for session in sessions_list:
        col1, col2 = st.columns([4, 1])
        with col1:
            # 加载会话信息
            if st.button(session, width = "stretch", icon = "📂", key = f"load_{session}", type = "primary" if session == st.session_state.current_session else "secondary"):
                load_session(session)
                st.rerun() # 刷新页面

        with col2:
            # 删除会话信息
            if st.button("", width = "stretch", icon = "❌️", key = f"delete_{session}"):
                delte_session(session)
                st.rerun() # 刷新页面

    # 伴侣信息
    st.sidebar.subheader("伴侣信息")

    # 昵称输入框
    nick_name = st.text_input("昵称", placeholder="请输入伴侣的昵称", value=st.session_state.nick_name)
    # 性格输入框
    nature = st.text_area("性格", placeholder="请输入伴侣的性格描述", value=st.session_state.nature)
    

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
            {"role": "system", "content": system_prompt % (st.session_state.nick_name, st.session_state.nature)},
            *st.session_state.messages
        ],
        stream = True,
        reasoning_effort = "high",
        extra_body = {"thinking": {"type": "enabled"}}
    )

    # 输出大模型返回的结果 (非流式输出的解析方式)
    # print("<---------- 大模型返回的结果：", response.choices[0].message.content)
    # st.chat_message("assistant").write(response.choices[0].message.content)

    # 输出大模型返回的结果 (流式输出的解析方式)
    response_message = st.empty() # 创建一个占位组件，用于后续更新大模型返回的结果
    full_response = ""
    for chunk in response:
        if chunk.choices[0].delta.content is not None:
            content = chunk.choices[0].delta.content
            full_response += content
            response_message.chat_message("assistant").write(full_response) # 实时更新大模型返回的结果

    # 保存大模型返回的结果到聊天记录中
    # st.session_state.messages.append({"role": "assistant", "content": response.choices[0].message.content})
    st.session_state.messages.append({"role": "assistant", "content": full_response})

    # 保存当前会话数据到本地 JSON 文件中
    save_session()